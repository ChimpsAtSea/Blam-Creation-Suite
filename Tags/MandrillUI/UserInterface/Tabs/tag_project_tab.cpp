#include "mandrillui-private-pch.h"

#include <AudioConversion\audioconversion-platform-pch.h>
#include <AudioConversion\audioconversion-public-pch.h>

static void export_sounds(const wchar_t* export_directory, c_tag_project& tag_project, bool export_wav, bool export_xma)
{
	h_tag* const* tag_instances;
	unsigned long tag_instance_count;
	tag_project.get_tag_instances(tag_instances, tag_instance_count);

	blofeld::halo3::pc64::h_sound_cache_file_gestalt_struct_definition* sound_cache_file_gestalt = nullptr;
	for (unsigned long tag_instance_index = 0; tag_instance_index < tag_instance_count; tag_instance_index++)
	{
		h_tag& tag = *tag_instances[tag_instance_index];

		if (tag.group->tag_group.group_tag == blofeld::halo3::pc64::SOUND_CACHE_FILE_GESTALT_TAG)
		{
			sound_cache_file_gestalt = dynamic_cast<blofeld::halo3::pc64::h_sound_cache_file_gestalt_struct_definition*>(&tag);
			break;
		}
	}
	ASSERT(sound_cache_file_gestalt != nullptr);

	for (unsigned long tag_instance_index = 0; tag_instance_index < tag_instance_count; tag_instance_index++)
	{
		h_tag& tag = *tag_instances[tag_instance_index];


		if (tag.group->tag_group.group_tag == blofeld::halo3::pc64::CACHE_FILE_SOUND_TAG)
		{
			blofeld::halo3::pc64::h_cache_file_sound_struct_definition* cache_file_sound = dynamic_cast<blofeld::halo3::pc64::h_cache_file_sound_struct_definition*>(&tag);
			ASSERT(cache_file_sound != nullptr);

			h_resource* resource = cache_file_sound->sound_data_resource.value;

			if (resource)
			{
				const void* resource_buffer;
				unsigned long resource_buffer_size;
				if (BCS_SUCCEEDED(resource->add_reference(resource_buffer, resource_buffer_size)))
				{
					using namespace blofeld::halo3::pc64;

					blofeld::halo3::pc64::h_sound_gestalt_codec_block& codec = sound_cache_file_gestalt->codecs_block[cache_file_sound->codec_index];
					
					unsigned long const pitch_range_start_index = cache_file_sound->first_pitch_range_index.value;
					unsigned long const pitch_range_end_index = pitch_range_start_index + cache_file_sound->pitch_range_count.value;
					for (unsigned long pitch_range_index = pitch_range_start_index; pitch_range_index < pitch_range_end_index; pitch_range_index++)
					{
						blofeld::halo3::pc64::h_sound_gestalt_pitch_ranges_block& pitch_range = sound_cache_file_gestalt->pitch_ranges_block[pitch_range_index];

						h_string_id pitch_range_name = sound_cache_file_gestalt->import_names_block[pitch_range.name.value].import_name.value;
						unsigned long encoded_first_permutation_and_counts = pitch_range.encoded_first_permutation_and_counts.value;

						unsigned long permutation_start_index = (encoded_first_permutation_and_counts >> 0) & 0x000FFFFF;
						unsigned long total_permutation_count = (encoded_first_permutation_and_counts >> 20) & 0x3F;
						unsigned long required_only_permutation_count = (encoded_first_permutation_and_counts >> 26) & 0x3F;

						debug_point;

						unsigned long const permutation_end_index = permutation_start_index + total_permutation_count;
						for (unsigned long permutation_index = permutation_start_index; permutation_index < permutation_end_index; permutation_index++)
						{
							blofeld::halo3::pc64::h_sound_gestalt_permutations_block& permutation = sound_cache_file_gestalt->permutations_block[permutation_index];
							h_string_id permutation_name = sound_cache_file_gestalt->import_names_block[permutation.name].import_name.value;

							debug_point;

							const char* _tag_filepath = tag.tag_filepath.c_str();
							const char* _permutation_name = permutation_name.c_str();

							unsigned long const chunk_count = permutation.chunk_count.value;
							if (chunk_count == 1)
							{
								unsigned long const chunk_start_index = permutation.first_chunk_index.value;
								unsigned long const chunk_end_index = chunk_start_index + chunk_count;
								for (unsigned long chunk_index = chunk_start_index; chunk_index < chunk_end_index; chunk_index++)
								{
									blofeld::halo3::pc64::h_sound_permutation_chunk_block& chunk = sound_cache_file_gestalt->chunks_block[chunk_index];

									c_long_designator<6, 0> size_and_flags;
									size_and_flags.set_raw_designator(chunk.encoded_size_and_flags.value);
									unsigned long sample_size = size_and_flags.get_primary_index();
									unsigned long flags = size_and_flags.get_secondary_index();
									unsigned long file_offset = chunk.file_offset.value;

									const char* sample_data_start = static_cast<const char*>(resource_buffer) + file_offset;
									const char* sample_data_end = sample_data_start + sample_size;

									long number_of_channels = 0;
									switch (codec.encoding.value)
									{
									case _sound_encoding_enum_mono:
										number_of_channels = 1;
										break;
									case _sound_encoding_enum_stereo:
										number_of_channels = 2;
										break;
									case _sound_encoding_enum_quad:
										number_of_channels = 4;
										break;
									case _sound_encoding_enum__51:
										number_of_channels = 6;
										break;
									case _sound_encoding_enum_codec:
										number_of_channels = 1;
										break;
									}

									long samples_per_second = 0;
									switch (codec.sample_rate.value)
									{
									case _sound_sample_rate_enum__22khz:
										samples_per_second = 22050;
										break;
									case _sound_sample_rate_enum__44khz:
										samples_per_second = 44100;
										break;
									case _sound_sample_rate_enum__32khz:
										samples_per_second = 32000;
										break;
									case _sound_sample_rate_enum__48khz:
										samples_per_second = 48000;
										break;
									}

									long riff_chunk_id = byteswap('RIFF');
									long riff_chunk_size = 0;
									long riff_chunk_data = byteswap('WAVE');

									long format_chunk_id = byteswap('fmt ');
									long format_chunk_size = sizeof(XMA2WAVEFORMATEX);

									long data_chunk_header = byteswap('data');
									long data_chunk_size = sample_size;
									XMA2WAVEFORMATEX xma2_wave_format = {};

									riff_chunk_size += sizeof(riff_chunk_data);
									riff_chunk_size += sizeof(format_chunk_id);
									riff_chunk_size += sizeof(format_chunk_size);
									riff_chunk_size += format_chunk_size;
									riff_chunk_size += sizeof(data_chunk_header);
									riff_chunk_size += sizeof(data_chunk_size);
									riff_chunk_size += data_chunk_size;

									{
										xma2_wave_format.wfx.wFormatTag = WAVE_FORMAT_XMA2;										//    wFormatTag;        // Audio format type; always WAVE_FORMAT_XMA2														
										xma2_wave_format.wfx.nChannels = static_cast<WORD>(number_of_channels);					//    nChannels;         // Channel count of the decoded audio
										xma2_wave_format.wfx.nSamplesPerSec = samples_per_second;								//    nSamplesPerSec;    // Sample rate of the decoded audio
										xma2_wave_format.wfx.nAvgBytesPerSec = 0;												//    nAvgBytesPerSec;   // Used internally by the XMA encoder
										xma2_wave_format.wfx.nBlockAlign = 2;													//    nBlockAlign;       // Decoded sample size; channels * wBitsPerSample / 8
										xma2_wave_format.wfx.wBitsPerSample = 16;												//    wBitsPerSample;    // Bits per decoded mono sample; always 16 for XMA
										xma2_wave_format.wfx.cbSize = sizeof(xma2_wave_format) - sizeof(WAVEFORMATEX);			//    cbSize;            // Size in bytes of the rest of this structure (34)

										xma2_wave_format.NumStreams = 1;														// Number of audio streams (1 or 2 channels each)
										xma2_wave_format.ChannelMask = 0;														// Spatial positions of the channels in this file,
																																// stored as SPEAKER_xxx values (see audiodefs.h)
										xma2_wave_format.SamplesEncoded = permutation.uncompressed_sample_count.value;			// Total number of PCM samples the file decodes to
										xma2_wave_format.BytesPerBlock = 2048;													// XMA block size (but the last one may be shorter)
										xma2_wave_format.PlayBegin = chunk.xma2_source_buffer_sample_start.value;				// First valid sample in the decoded audio
										xma2_wave_format.PlayLength = chunk.xma2_source_buffer_sample_end.value;				// Length of the valid part of the decoded audio
										xma2_wave_format.LoopBegin = 0;															// Beginning of the loop region in decoded sample terms
										xma2_wave_format.LoopLength = 0;														// Length of the loop region in decoded sample terms
										xma2_wave_format.LoopCount = 0;															// Number of loop repetitions; 255 = infinite
										xma2_wave_format.EncoderVersion = 4;													// Version of XMA encoder that generated the file
										xma2_wave_format.BlockCount = static_cast<WORD>(sample_size / 2048);					// XMA blocks in file (and entries in its seek table)
									}
									char* xma_file_data;
									unsigned long xma_file_data_size = 0;
									{
#define enqueue_size(size) xma_file_data_size += (size)
										enqueue_size(sizeof(riff_chunk_id));
										enqueue_size(sizeof(riff_chunk_size));
										enqueue_size(sizeof(riff_chunk_data));
										enqueue_size(sizeof(format_chunk_id));
										enqueue_size(sizeof(format_chunk_size));
										enqueue_size(sizeof(xma2_wave_format));
										enqueue_size(sizeof(data_chunk_header));
										enqueue_size(sizeof(data_chunk_size));
										enqueue_size(data_chunk_size);
#undef enqueue_size

										xma_file_data = new() char[xma_file_data_size];
										char* xma_file_data_pos = xma_file_data;
#define enqueue_data(pointer, size) memcpy(xma_file_data_pos, (pointer), (size)); xma_file_data_pos += (size)
										enqueue_data(&riff_chunk_id, sizeof(riff_chunk_id));
										enqueue_data(&riff_chunk_size, sizeof(riff_chunk_size));
										enqueue_data(&riff_chunk_data, sizeof(riff_chunk_data));
										enqueue_data(&format_chunk_id, sizeof(format_chunk_id));
										enqueue_data(&format_chunk_size, sizeof(format_chunk_size));
										enqueue_data(&xma2_wave_format, sizeof(xma2_wave_format));
										enqueue_data(&data_chunk_header, sizeof(data_chunk_header));
										enqueue_data(&data_chunk_size, sizeof(data_chunk_size));
										enqueue_data(sample_data_start, sample_size);
#undef enqueue_data

									}

									debug_point;

									if (export_wav)
									{
										void* wave_file_data;
										unsigned long long wave_file_data_size;
										BCS_RESULT decode_rs = decode_xma2_to_wav(xma_file_data, xma_file_data_size, wave_file_data, wave_file_data_size);
										if (BCS_SUCCEEDED(decode_rs))
										{
											c_fixed_path wav_output_filepath;
											wav_output_filepath.format("%Sdata\\%s\\%s.wav", export_directory, _tag_filepath, permutation_name);
											filesystem_write_file_from_memory(wav_output_filepath, wave_file_data, wave_file_data_size);

											tracked_free(wave_file_data);
										}

										debug_point;
									}
									if (export_xma)
									{
										c_fixed_path xma_output_filepath;
										xma_output_filepath.format("%Sdata\\%s\\%s.xma", export_directory, _tag_filepath, permutation_name);

										filesystem_write_file_from_memory(xma_output_filepath, xma_file_data, xma_file_data_size);

										tracked_free(xma_file_data);

										debug_point;
									}


									debug_point;
								}
							}
							else
							{
								debug_point;
							}
							debug_point;
						}

						debug_point;
					}

					debug_point;

					resource->remove_reference();
				}
			}
			else
			{
				debug_point;
			}

			debug_point;
		}

	}
}

c_tag_project_tab::c_tag_project_tab(const wchar_t* filepath, c_tag_project& tag_project, c_mandrill_tab& parent) :
	c_mandrill_tab("Tag Project", "Tag Project", &parent, false),
	tag_project(tag_project),
	user_interface(*search_parent_tab_type<c_mandrill_user_interface>()),
	project_filepath(filepath),
	search_buffer(),
	file_browser(),
	show_export_sounds_file_dialogue(),
	sound_export_wav(),
	sound_export_xma()
{
	const char* tag_filepaths[128] = {};
	unsigned long num_tag_filepaths = _countof(tag_filepaths);
	if (BCS_SUCCEEDED(command_line_get_arguments("autotag", tag_filepaths, num_tag_filepaths)) && num_tag_filepaths > 0)
	{
		for (unsigned long tag_filepath_index = 0; tag_filepath_index < num_tag_filepaths; tag_filepath_index++)
		{
			const char* tag_filepath = tag_filepaths[tag_filepath_index];
			open_tag_by_search_name(tag_filepath);
		}
	}

	if (tag_project.engine_platform_build.engine_type == _engine_type_halo3)
	{
		bool export_wav = BCS_SUCCEEDED(command_line_has_argument("autoexportsoundswav"));
		bool export_xma = BCS_SUCCEEDED(command_line_has_argument("autoexportsoundsxma"));
		if (export_wav || export_xma)
		{
			export_sounds(L"", tag_project, export_wav, export_xma);
		}
	}

}

c_tag_project_tab::~c_tag_project_tab()
{
	delete& tag_project;
}

c_tag_project& c_tag_project_tab::get_tag_project() const
{
	return tag_project;
}

void c_tag_project_tab::open_tag_by_search_name(const char* tag_name)
{
	h_tag* const* tag_instances = nullptr;
	unsigned long num_tag_instances = 0;
	if (BCS_SUCCEEDED(tag_project.get_tag_instances(tag_instances, num_tag_instances)))
	{
		for (unsigned long tag_instance_index = 0; tag_instance_index < num_tag_instances; tag_instance_index++)
		{
			h_tag* tag = tag_instances[tag_instance_index];
			bool is_match =
				_stricmp(tag_name, tag->tag_filepath.c_str()) == 0 ||
				_stricmp(tag_name, tag->tag_filename.c_str()) == 0;
			if (is_match)
			{
				open_tag_interface_tab(*tag);
				return;
			}
		}
	}
}

c_high_level_tag_tab& c_tag_project_tab::open_tag_interface_tab(h_tag& tag)
{
	for (c_mandrill_tab* tab : children)
	{
		if (c_high_level_tag_tab* high_level_tag_tab = dynamic_cast<c_high_level_tag_tab*>(tab))
		{
			if (&high_level_tag_tab->get_tag() == &tag)
			{
				next_selected_tab = high_level_tag_tab;
				return *high_level_tag_tab;
			}
		}
	}

	c_high_level_tag_tab* high_level_tag_tab = new() c_high_level_tag_tab(tag_project, tag, *this);
	add_tab(*high_level_tag_tab);
	next_selected_tab = high_level_tag_tab;

	return *high_level_tag_tab;
}

void c_tag_project_tab::render_search_box()
{
	const char* search_reccomendation = "<search for tag>";
	ImDrawList* draw_list = ImGui::GetWindowDrawList();

	ImGui::Dummy({ 10.0f, 0.0f });
	ImGui::SameLine();
	ImGui::PushItemWidth(ImGui::GetWindowContentRegionWidth() - 75.0f);
	ImGuiInputTextFlags input_text_flags = 0;
	ImVec2 pos = ImGui::GetCursorScreenPos();
	ImGui::InputText("##Search", search_buffer.str(), search_buffer.capacity(), input_text_flags);
	if (!ImGui::IsItemActive() && search_buffer.empty())
	{
		draw_list->AddText({ pos.x + 4.0f, pos.y + 4.0f }, ImGui::ColorConvertFloat4ToU32(MANDRILL_THEME_TEXT(0.25)), search_reccomendation);
	}
	ImGui::SameLine();
	if (ImGui::Button(ICON_FA_XMARK))
	{
		search_buffer.clear();
	}
	ImGui::SameLine();
	ImGui::Dummy({ 10.0f, 0.0f });
}

void c_tag_project_tab::render_tags_list_search()
{
	h_tag* const* tag_instances = nullptr;
	unsigned long num_tag_instances = 0;
	if (BCS_SUCCEEDED(tag_project.get_tag_instances(tag_instances, num_tag_instances)))
	{
		for (unsigned long tag_instance_index = 0; tag_instance_index < num_tag_instances; tag_instance_index++)
		{
			h_tag* tag = tag_instances[tag_instance_index];
			//const char* tag_path_group_id = tag_interface.get_path_with_group_id_cstr();
			//const char* tag_path_group_name = tag_interface.get_path_with_group_name_cstr();

			//const char* tag_display_with_group_name = user_interface.get_use_full_file_length_display()
			//	? tag_interface.get_path_with_group_name_cstr()
			//	: tag_interface.get_name_with_group_name_cstr();

			if (!search_buffer.empty())
			{
				if (strstr(tag->tag_filepath.data, search_buffer.c_str()) == nullptr)
				{
					continue;
				}
			}

			bool is_active = search_selected_tag_interface == tag;
			bool selectable_activated = ImGui::Selectable(tag->tag_filepath.c_str(), is_active, ImGuiSelectableFlags_AllowDoubleClick);

			if (ImGui::IsItemHovered())
			{
				ImGui::BeginTooltip();
				ImGui::Text(tag->tag_filepath.c_str());
				ImGui::EndTooltip();
			}
			if (selectable_activated && ImGui::IsMouseDoubleClicked((ImGuiMouseButton_Left)))
			{
				search_selected_tag_interface = tag;
				open_tag_interface_tab(*tag);
				search_selected_tag_interface = nullptr;
			}
			if (ImGui::BeginPopupContextItem()) // <-- This is using IsItemHovered()
			{
				if (ImGui::MenuItem("Copy as path"))
				{
					clipboard_set_text(tag->tag_filepath);
				}
				ImGui::EndPopup();
			}
		}
	}
}

void c_tag_project_tab::render_tags_list_tree()
{
	h_group* const* groups;
	unsigned long group_count;
	if (BCS_SUCCEEDED(tag_project.get_tag_groups(groups, group_count)))
	{
		for (unsigned long group_index = 0; group_index < group_count; group_index++)
		{
			h_group* group = groups[group_index];
			const unsigned long tag_interfaces_count = static_cast<unsigned long>(group->tags.size());

			const char* group_name = group->tag_group.name;
			const char* group_short_name = group->tag_group.group_tag_short_string;

			bool display_group = tag_interfaces_count > 0;

			if (!display_group) continue;


			bool tree_node_selected = ImGui::TreeNode(group_short_name, "%s - %s", group_name, group_short_name);
			if (tree_node_selected)
			{
				for (h_tag* tag : group->tags)
				{
					const char* tag_display_with_group_id = tag->tag_filepath.c_str();

					static ImGuiTreeNodeFlags base_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;
					if (ImGui::TreeNodeEx(tag, base_flags | ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen, "%s", tag_display_with_group_id))
					{
						if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
						{
							open_tag_interface_tab(*tag);
						}
					}
					if (ImGui::BeginPopupContextItem()) // <-- This is using IsItemHovered()
					{
						if (ImGui::MenuItem("Copy as path"))
						{
							clipboard_set_text(tag->tag_filepath);
						}
						ImGui::EndPopup();
					}
				}

				ImGui::TreePop();
			}
		}
	}
}

void c_tag_project_tab::render_explorer_bar()
{
	ImGui::Dummy({ 0.0f, 10.0f });

	render_search_box();

	ImGui::Dummy({ 0.0f, 10.0f });
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 25, 8 });
	if (search_buffer.empty())
	{
		if (ImGui::BeginTabBar("##fileview"))
		{
			if (ImGui::BeginTabItem("Tags"))
			{
				ImGui::Dummy({ 0.0f, 1.0f });
				ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 4, 4 });

				ImGui::BeginChild("left column", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar);

				render_tags_list_tree();

				ImGui::EndChild();

				ImGui::PopStyleVar();
				ImGui::EndTabItem();
			}


			ImGui::EndTabBar();
		}
	}
	else
	{
		ImGui::BeginChild("left column", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_HorizontalScrollbar);

		render_tags_list_search();

		ImGui::EndChild();

	}
	ImGui::PopStyleVar();
}

void c_tag_project_tab::render_impl()
{
	if (c_mandrill_user_interface::get_show_explorer_bar_setting())
	{
		ImGui::Columns(2, "##navigation");
		ImGui::SetColumnOffset(1, c_mandrill_user_interface::get_explorer_bar_width_setting());
		ImGui::Separator();
		{
			ImGui::BeginGroup();
			ImVec2 size = ImGui::GetContentRegionAvail();
			if (size.x < 200.0f)
			{
				size.x = 200.0f;
			}
			ImGui::BeginChild("left column", size, false, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

			render_explorer_bar();

			ImGui::EndChild();
			ImGui::EndGroup();
		}
		if (ImGui::IsMouseDragging(ImGuiMouseButton_Left))
		{
			c_mandrill_user_interface::set_explorer_bar_width_setting(ImGui::GetItemRectSize().x + 16.0f);
			
		}
		if (c_mandrill_user_interface::get_explorer_bar_width_setting() < 200.0f)
		{
			c_mandrill_user_interface::set_explorer_bar_width_setting(200.0f + 16.0f);
		}
		ImGui::NextColumn();
	}
	{
		ImGui::BeginGroup();
		ImGui::BeginChild("right column", {}, false);

		if (ImGui::BeginTabBar("##tagsview"))
		{
			c_mandrill_tab* select_tab = next_selected_tab;
			next_selected_tab = nullptr; // take a copy here as child render calls can set this value
			//for (c_mandrill_tab& tab : c_reference_loop(children.data(), children.size()))
			// ###HACK This is super bad, but the memory is being resized during runtime.
			// this needs to be replaced with a thread safe linked list
			std::vector<c_mandrill_tab*> _children = children;
			for (c_mandrill_tab* tab : _children)
			{
				tab->render(tab == select_tab);
			}

			ImGui::EndTabBar();
		}

		ImGui::EndChild();
		ImGui::EndGroup();
		ImGui::Columns(1);
	}
}

bool c_tag_project_tab::render_menu_gui_impl(e_menu_render_type menu_render_type)
{
	if (menu_render_type == _menu_render_type_root_file && is_selected())
	{
		if (ImGui::MenuItem("Close Project"))
		{
			_is_open = false;
		}
		ImGui::Separator();

		ImGui::MenuItem("New Tag");
		ImGui::Separator();

		ImGui::MenuItem("Compile Cache File");

		if (tag_project.engine_platform_build.engine_type == _engine_type_halo3)
		{
			if (ImGui::MenuItem("Export Sounds"))
			{
				show_export_sounds_file_dialogue = true;
				sound_export_wav = true;
				sound_export_xma = true;
			}
			if (ImGui::MenuItem("Export Sounds (WAV only)"))
			{
				show_export_sounds_file_dialogue = true;
				sound_export_wav = true;
				sound_export_xma = false;
			}
			if (ImGui::MenuItem("Export Sounds (XMA only)"))
			{
				show_export_sounds_file_dialogue = true;
				sound_export_wav = false;
				sound_export_xma = true;
			}
		}


		ImGui::Separator();
	}
	if (menu_render_type == _menu_render_type_root && is_selected())
	{
		if (ImGui::BeginMenu("Project"))
		{
			for (c_mandrill_tab* tab : children)
			{
				tab->render_menu_gui(_menu_render_type_child);
			}

			ImGui::EndMenu();
		}

		for (c_mandrill_tab* tab : children)
		{
			tab->render_menu_gui(_menu_render_type_root);
		}
	}
	return true;
}

void c_tag_project_tab::render_file_dialogue_gui_impl()
{
	if (ImGui::BeginAsyncOpenFolderDialog(&file_browser, "Export Sounds Directory", show_export_sounds_file_dialogue))
	{
		if (ImGui::AsyncFileDialogIsValid())
		{
			const wchar_t* export_directory = ImGui::AsyncFileDialogGetFilepathWideChar();

			export_sounds(export_directory, tag_project, sound_export_wav, sound_export_xma);

			debug_point;
		}
		debug_point;

		ImGui::EndAsyncFileDialog();
	}
	show_export_sounds_file_dialogue = false;
}

void c_tag_project_tab::render_game_layer_impl()
{

}
