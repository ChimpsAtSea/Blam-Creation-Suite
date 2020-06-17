/*
 * ImGui-Addons File Dialog
 * This file is part of ImGui-Addons https://github.com/gallickgunner/ImGui-Addons
 * Licensed under the MIT license.
 * Commit master / 730f379845f1a874ab4f33d66d4a066d3b0b187a
 */

#ifndef IMGUIFILEBROWSER_H
#define IMGUIFILEBROWSER_H

namespace ImGuiAddons
{
	class ImGuiFileBrowser
	{
	public:
		ImGuiFileBrowser(std::string path = "");
		~ImGuiFileBrowser();


		/* Use this to show an open file dialog. The function takes label for the window,
		 * the size and optionally the extensions that are valid for opening.
		 */
		bool show_open_file_dialog(std::string label, ImVec2 sz_xy, std::string valid_types = "");

		/* Use this to open a save file dialog. The function takes label for the window,
		 * the size and the extensions or types of files allowed for saving
		 */
		bool show_save_file_dialog(std::string label, ImVec2 sz_xy, std::string save_types, std::string filename = "");

		const char* get_current_path() const { return current_path.c_str(); }
		const char* get_selected_file_name() const { return selected_fn.empty() ? nullptr : selected_fn.c_str(); }
		void set_selected_file_name(const char* filename) { selected_fn = filename; }
		const char* get_selected_extension() const { return ext.empty() ? nullptr : ext.c_str(); }

	private:
		void set_save_file_name(const char* filename)
		{
			snprintf(save_fn, _countof(save_fn) - 1, "%s", filename);
			save_fn[_countof(save_fn)] = 0;
		}
		const char* get_save_file_name() const
		{
			return save_fn;
		}

		/* Use this to show an open file dialog. The function takes label for the window,
		 * the size and optionally the extensions that are valid for opening.
		 */
		bool showOpenFileDialogInternal(std::string label, ImVec2 sz_xy, std::string valid_types);

		/* Use this to open a save file dialog. The function takes label for the window,
		 * the size and the extensions or types of files allowed for saving
		 */
		bool showSaveFileDialogInternal(std::string label, ImVec2 sz_xy, std::string save_types);
		std::string selected_fn;    // Store the opened/saved file name. Should only be accessed when above functions return true else may contain garbage.
		std::string ext;    // Store the saved file extension

	private:
		struct Info
		{
			Info(std::string name, bool is_hidden) : name(name), is_hidden(is_hidden)
			{
			}
			std::string name;
			bool is_hidden;
		};

		static std::string wStringToString(const wchar_t* wchar_arr);
		static bool alphaSortComparator(const Info& a, const Info& b);
		bool validateFile();
		bool readDIR(std::string path);
		bool onNavigationButtonClick(int idx);
		bool onDirClick(int idx, bool show_drives, bool is_save_dialog);
#if defined (WIN32) || defined (_WIN32) || defined (__WIN32)
		bool loadWindowsDrives(); // Windows Exclusive
#endif
		void parsePathTabs(std::string str);
		void showErrorModal();
		void showInvalidFileModal();
		void clearOldEntries();
		void closeDialog();

		int col_items_limit, selected_idx;
		float col_width;
		bool show_hidden, is_dir, filter_dirty;
		std::vector<std::string> valid_exts;
		std::vector<std::string> current_dirlist;
		std::vector<Info> subdirs;
		std::vector<Info> subfiles;
		std::string current_path, error_msg, error_title;

		/* These variables are used specifically when user calls openFileDialog. They are of no use for opening save file dialog */
		ImGuiTextFilter filter;
		std::string valid_types;
		std::vector<Info*> filtered_dirs; // Note: We don't need to call delete. It's just for storing filtered items from subdirs and subfiles so we don't use PassFilter every frame.
		std::vector<Info*> filtered_files;

		//These vars are used specifically for save file dialog.
		char save_fn[500];
		int selected_ext_idx;
		bool show_popup_next_run;
	};
}


#endif // IMGUIFILEBROWSER_H
