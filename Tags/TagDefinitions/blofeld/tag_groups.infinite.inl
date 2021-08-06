
namespace blofeld
{
	const s_tag_group* tag_groups_infinite[] =
	{
		//ANYTAG_TAG = 'aTag'
		&blofeld::infinite::AnyTag_group,

		//AMBIENTACTIONPOINTDEFINITIONTAG_TAG = 'aaap'
		&blofeld::infinite::AmbientActionPointDefinitionTag_group,

		//ABC_TAG = 'abc*'
		&blofeld::infinite::abc_group,

		//ASSETCOLLECTION_TAG = 'acol'
		&blofeld::infinite::AssetCollection_group,

		//ACTORCELLENTRYTAG_TAG = 'actc'
		&blofeld::infinite::ActorCellEntryTag_group,

		//ASSET_DIALOGUE_TAG = 'adia'
		&blofeld::infinite::asset_dialogue_group,

		//AI_DIALOGUE_GLOBALS_TAG = 'adlg'
		&blofeld::infinite::ai_dialogue_globals_group,

		//AIRDROPSYSTEMGLOBALSDEFINITION_TAG = 'adrp'
		&blofeld::infinite::AirDropSystemGlobalsDefinition_group,

		//AUTOHLODSETTINGS_TAG = 'ahld'
		&blofeld::infinite::AutoHlodSettings_group,

		//AI_GLOBALS_TAG = 'aigl'
		&blofeld::infinite::ai_globals_group,

		//ATTACHED_LIGHT_CONE_TAG = 'alic'
		&blofeld::infinite::attached_light_cone_group,

		//ANIMATEDMESH_TAG = 'ames'
		&blofeld::infinite::AnimatedMesh_group,

		//ANIMGLOBALS_TAG = 'angb'
		&blofeld::infinite::animglobals_group,

		//XANIMNODEGRAPH_TAG = 'angt'
		&blofeld::infinite::XAnimNodeGraph_group,

		//ANIMSET_TAG = 'anim'
		&blofeld::infinite::AnimSet_group,

		//XANIMSTATEGRAPH_TAG = 'ansm'
		&blofeld::infinite::XAnimStateGraph_group,

		//ANTENNA_TAG = 'ant!'
		&blofeld::infinite::antenna_group,

		//ACTIONPRIORITYDATADEFINITIONTAG_TAG = 'apdd'
		&blofeld::infinite::ActionPriorityDataDefinitionTag_group,

		//ASSET_TAG = 'aset'
		&blofeld::infinite::asset_group,

		//ANIMATION_SKELETON_TAG = 'askt'
		&blofeld::infinite::animation_skeleton_group,

		//ASSET_SOUND_TAG = 'asou'
		&blofeld::infinite::asset_sound_group,

		//ASSET_CATEGORY_GLOBALS_TAG = 'atcg'
		&blofeld::infinite::asset_category_globals_group,

		//ATMOSPHERE_GLOBALS_TAG = 'atgf'
		&blofeld::infinite::atmosphere_globals_group,

		//ANIMTOKENGLOBALS_TAG = 'atkg'
		&blofeld::infinite::AnimTokenGlobals_group,

		//AUDIOTHREATGLOBALS_TAG = 'attd'
		&blofeld::infinite::AudioThreatGlobals_group,

		//DEATH_PROGRAM_SELECTOR_TAG = 'bdpd'
		&blofeld::infinite::death_program_selector_group,

		//BEHAVIORTREE_TAG = 'beht'
		&blofeld::infinite::BehaviorTree_group,

		//BINK_TAG = 'bink'
		&blofeld::infinite::bink_group,

		//BITMAP_DICTIONARY_TAG = 'bitd'
		&blofeld::infinite::bitmap_dictionary_group,

		//BITMAP_TAG = 'bitm'
		&blofeld::infinite::bitmap_group,

		//BITMAP_USAGE_TABLE_TAG = 'biut'
		&blofeld::infinite::bitmap_usage_table_group,

		//BSP_LIGHTING_VOLUMES_TAG = 'blvo'
		&blofeld::infinite::bsp_lighting_volumes_group,

		//BENCHMARKDEFINITION_TAG = 'bnch'
		&blofeld::infinite::BenchmarkDefinition_group,

		//UNITBOOSTDEFINITION_TAG = 'bost'
		&blofeld::infinite::UnitBoostDefinition_group,

		//BOTGLOBALSTAG_TAG = 'botg'
		&blofeld::infinite::BotGlobalsTag_group,

		//BITMAP_PACKAGE_SETTINGS_TAG = 'bpks'
		&blofeld::infinite::bitmap_package_settings_group,

		//BSP_VOLUMES_TAG = 'bspv'
		&blofeld::infinite::bsp_volumes_group,

		//CAGEDEFINITION_TAG = 'cage'
		&blofeld::infinite::CageDefinition_group,

		//CAGEGLOBALSDEFINITION_TAG = 'cagg'
		&blofeld::infinite::CageGlobalsDefinition_group,

		//CAMERA_ANIMATION_GRAPH_TAG = 'camg'
		&blofeld::infinite::camera_animation_graph_group,

		//UICAMERAPRESETS_TAG = 'caps'
		&blofeld::infinite::UICameraPresets_group,

		//COLLISION_DAMAGE_TAG = 'cddf'
		&blofeld::infinite::collision_damage_group,

		//COLLISIONFILTERDEFINITION_TAG = 'cfdf'
		&blofeld::infinite::CollisionFilterDefinition_group,

		//CAMERA_FX_SETTINGS_TAG = 'cfxs'
		&blofeld::infinite::camera_fx_settings_group,

		//CHARACTER_TAG = 'char'
		&blofeld::infinite::character_group,

		//CHROMA_DEFINITION_TAG = 'chrd'
		&blofeld::infinite::chroma_definition_group,

		//CHROMA_TAG = 'chrm'
		&blofeld::infinite::chroma_group,

		//COLLISIONLAYERAUDITCONFIGURATIONTAG_TAG = 'clac'
		&blofeld::infinite::collisionLayerAuditConfigurationTag_group,

		//ANIMCLIP_TAG = 'clip'
		&blofeld::infinite::animclip_group,

		//CLOTH_TAG = 'clwd'
		&blofeld::infinite::cloth_group,

		//CAMO_TAG = 'cmoe'
		&blofeld::infinite::camo_group,

		//CAMPAIGNGLOBALSDEFINITION_TAG = 'cmpg'
		&blofeld::infinite::CampaignGlobalsDefinition_group,

		//COMPOSITION_SCENE_TAG = 'cmps'
		&blofeld::infinite::composition_scene_group,

		//COMPOSER_TRANSITION_TAG = 'cmpt'
		&blofeld::infinite::composer_transition_group,

		//CAMPAIGNUPGRADES_TAG = 'cmpu'
		&blofeld::infinite::CampaignUpgrades_group,

		//CONTROLLER_MAPPING_TAG = 'cnmp'
		&blofeld::infinite::controller_mapping_group,

		//CONVERSATION_TAG = 'cnvo'
		&blofeld::infinite::Conversation_group,

		//CONVERSATIONTYPES_TAG = 'cnvt'
		&blofeld::infinite::ConversationTypes_group,

		//COLLECTIBLESDEFINITION_TAG = 'cole'
		&blofeld::infinite::CollectiblesDefinition_group,

		//COLLISION_MODEL_TAG = 'coll'
		&blofeld::infinite::collision_model_group,

		//COLOR_TABLE_TAG = 'colo'
		&blofeld::infinite::color_table_group,

		//CUSTOM_OBJECT_LIGHTING_TAG = 'colt'
		&blofeld::infinite::custom_object_lighting_group,

		//COMPOSITION_TAG = 'comp'
		&blofeld::infinite::composition_group,

		//CHEAP_PARTICLE_EMITTER_TAG = 'cpem'
		&blofeld::infinite::cheap_particle_emitter_group,

		//CHEAP_PARTICLE_TYPE_LIBRARY_TAG = 'cptl'
		&blofeld::infinite::cheap_particle_type_library_group,

		//CAMERA_SHAKE_TAG = 'csdt'
		&blofeld::infinite::camera_shake_group,

		//CUI_RESOURCES_TAG = 'cure'
		&blofeld::infinite::cui_resources_group,

		//CURVEDEFINITION_TAG = 'curv'
		&blofeld::infinite::CurveDefinition_group,

		//CUI_SCREEN_TAG = 'cusc'
		&blofeld::infinite::cui_screen_group,

		//CUI_STATIC_DATA_TAG = 'cust'
		&blofeld::infinite::cui_static_data_group,

		//COATINGMATERIALSET_TAG = 'cwms'
		&blofeld::infinite::CoatingMaterialSet_group,

		//DAMAGE_TAG = 'damg'
		&blofeld::infinite::damage_group,

		//DECORATOR_ASSET_TAG = 'dcat'
		&blofeld::infinite::decorator_asset_group,

		//DISPOSITIONCOLORS_TAG = 'dcgd'
		&blofeld::infinite::dispositionColors_group,

		//DECORATOR_PALETTE_TAG = 'dcpt'
		&blofeld::infinite::decorator_palette_group,

		//RUNTIME_DEC_TAG = 'dcrt'
		&blofeld::infinite::runtime_dec_group,

		//DECORATOR_SETTINGS_TAG = 'dcst'
		&blofeld::infinite::decorator_settings_group,

		//DECAL_SYSTEM_TAG = 'decs'
		&blofeld::infinite::decal_system_group,

		//DAMAGE_EFFECT_SOUNDS_TAG = 'desd'
		&blofeld::infinite::damage_effect_sounds_group,

		//DARKROOMASSEMBLY_TAG = 'dkam'
		&blofeld::infinite::DarkRoomAssembly_group,

		//DARKROOMASSETSPEC_TAG = 'dkas'
		&blofeld::infinite::DarkRoomAssetSpec_group,

		//DARKROOMCAMERASPEC_TAG = 'dkcs'
		&blofeld::infinite::DarkRoomCameraSpec_group,

		//DARKROOMLIGHTINGSPEC_TAG = 'dkls'
		&blofeld::infinite::DarkRoomLightingSpec_group,

		//DARKROOMANIMATIONSPEC_TAG = 'dkms'
		&blofeld::infinite::DarkRoomAnimationSpec_group,

		//DARKROOMRENDERSETTINGSSPEC_TAG = 'dkrs'
		&blofeld::infinite::DarkRoomRenderSettingsSpec_group,

		//DARKROOMSHOTLIST_TAG = 'dksl'
		&blofeld::infinite::DarkRoomShotList_group,

		//DARKROOMSCREENSHOTSETTINGSSPEC_TAG = 'dkss'
		&blofeld::infinite::DarkRoomScreenshotSettingsSpec_group,

		//DAMAGE_RESPONSE_DEFINITION_TAG = 'drdf'
		&blofeld::infinite::damage_response_definition_group,

		//DAMAGEREPORTINGDISPLAYGLOBALS_TAG = 'drdg'
		&blofeld::infinite::DamageReportingDisplayGlobals_group,

		//DIALOGUE_SYSTEM_DATA_TAG = 'dsdt'
		&blofeld::infinite::dialogue_system_data_group,

		//DYNAMICWORLDSTATEGLOBALS_TAG = 'dwsg'
		&blofeld::infinite::DynamicWorldStateGlobals_group,

		//EXPORTEDENCOUNTERBEHAVIORTREEDEFINITION_TAG = 'ebtt'
		&blofeld::infinite::ExportedEncounterBehaviorTreeDefinition_group,

		//EFFECT_EXPOSURE_TAG = 'efex'
		&blofeld::infinite::effect_exposure_group,

		//EFFECT_TAG = 'effe'
		&blofeld::infinite::effect_group,

		//EFFECT_GLOBALS_TAG = 'effg'
		&blofeld::infinite::effect_globals_group,

		//GENERATOR_SYSTEM_TAG = 'efge'
		&blofeld::infinite::generator_system_group,

		//EFFECT_WIND_TAG = 'efwi'
		&blofeld::infinite::effect_wind_group,

		//EFFECT_GLOBAL_FORCE_TAG = 'egfd'
		&blofeld::infinite::effect_global_force_group,

		//EMBLEM_GLOBALS_TAG = 'embg'
		&blofeld::infinite::emblem_globals_group,

		//EMBLEM_TAG = 'embl'
		&blofeld::infinite::emblem_group,

		//EMBLEM_THEME_GLOBALS_TAG = 'emth'
		&blofeld::infinite::emblem_theme_globals_group,

		//EMITTER_TAG = 'emtr'
		&blofeld::infinite::emitter_group,

		//EXPLICITSHADERS_TAG = 'exs*'
		&blofeld::infinite::explicitshaders_group,

		//EXPLICITSHADERTABLE_TAG = 'exst'
		&blofeld::infinite::ExplicitShaderTable_group,

		//FORWARDFASTLIGHTING_TAG = 'fafl'
		&blofeld::infinite::ForwardFastLighting_group,

		//FANFAREDEFINITION_TAG = 'fanf'
		&blofeld::infinite::FanfareDefinition_group,

		//FIXEDDEPTHQUADTREE_TAG = 'fdqt'
		&blofeld::infinite::FixedDepthQuadTree_group,

		//ANIMFRAMEEVENTS_TAG = 'fel0'
		&blofeld::infinite::AnimFrameEvents_group,

		//ANIMFRAMEEVENTSAUDIO_TAG = 'fel1'
		&blofeld::infinite::AnimFrameEventsAudio_group,

		//ANIMFRAMEEVENTSFX_TAG = 'fel2'
		&blofeld::infinite::AnimFrameEventsFx_group,

		//ANIMFRAMEEVENTSAUDIO_V0_TAG = 'fel3'
		&blofeld::infinite::AnimFrameEventsAudio_v0_group,

		//ANIMFRAMEEVENTSFX_V0_TAG = 'fel4'
		&blofeld::infinite::AnimFrameEventsFx_v0_group,

		//FRAME_EVENT_LIST_AUDIO_TAG = 'fela'
		&blofeld::infinite::frame_event_list_audio_group,

		//FRAME_EVENT_LIST_ANIM_TAG = 'felb'
		&blofeld::infinite::frame_event_list_anim_group,

		//FRAME_EVENT_LIST_EFFECT_TAG = 'fele'
		&blofeld::infinite::frame_event_list_effect_group,

		//FLOCK_TAG = 'flck'
		&blofeld::infinite::flock_group,

		//FLINCH_IMPULSE_TAG = 'flni'
		&blofeld::infinite::flinch_impulse_group,

		//FLINCH_SYSTEM_TAG = 'flns'
		&blofeld::infinite::flinch_system_group,

		//FORGE_LOOPING_SOUND_CATEGORIES_TAG = 'flsc'
		&blofeld::infinite::forge_looping_sound_categories_group,

		//TYPEFACE_TAG = 'fntf'
		&blofeld::infinite::typeface_group,

		//FORGENAMEDTAGLISTS_TAG = 'fntl'
		&blofeld::infinite::ForgeNamedTagLists_group,

		//WPF_FONT_SET_TAG = 'fnts'
		&blofeld::infinite::wpf_font_set_group,

		//FOLIAGE_ASSET_TAG = 'foat'
		&blofeld::infinite::foliage_asset_group,

		//ATMOSPHERE_FOG_TAG = 'fogg'
		&blofeld::infinite::atmosphere_fog_group,

		//FORGEKIT_TAG = 'foki'
		&blofeld::infinite::forgekit_group,

		//WPF_FONT_TAG = 'font'
		&blofeld::infinite::wpf_font_group,

		//FORGEOBJECTDATA_TAG = 'food'
		&blofeld::infinite::ForgeObjectData_group,

		//FORGEOBJECTMANIFEST_TAG = 'foom'
		&blofeld::infinite::ForgeObjectManifest_group,

		//MATERIAL_EFFECTS_TAG = 'foot'
		&blofeld::infinite::material_effects_group,

		//FORGE_SOUNDS_TAG = 'fora'
		&blofeld::infinite::forge_sounds_group,

		//FORGE_GLOBALS_TAG = 'forg'
		&blofeld::infinite::forge_globals_group,

		//FORMATION_TAG = 'form'
		&blofeld::infinite::formation_group,

		//FORGEOBJECTSCRIPTPROPERTYMENUITEMDEFINITIONS_TAG = 'fosp'
		&blofeld::infinite::ForgeObjectScriptPropertyMenuItemDefinitions_group,

		//FORGEPALETTEDEFINITION_TAG = 'fpal'
		&blofeld::infinite::ForgePaletteDefinition_group,

		//FRAME_EVENT_LIST_TAG = 'frms'
		&blofeld::infinite::frame_event_list_group,

		//FORGESOUNDLISTDEFINITION_TAG = 'fsld'
		&blofeld::infinite::ForgeSoundListDefinition_group,

		//FORGE_SOUND_RESPONSE_SOUNDS_TAG = 'fsrs'
		&blofeld::infinite::forge_sound_response_sounds_group,

		//FORGETELESCOPINGASSET_TAG = 'ftat'
		&blofeld::infinite::ForgeTelescopingAsset_group,

		//COMPONENTDEFINITION_TAG = 'fuic'
		&blofeld::infinite::ComponentDefinition_group,

		//SCREENDEFINITION_TAG = 'fuis'
		&blofeld::infinite::ScreenDefinition_group,

		//EFFECTKIT_TAG = 'fxkt'
		&blofeld::infinite::effectKit_group,

		//GAME_ENGINE_GLOBALS_TAG = 'gegl'
		&blofeld::infinite::game_engine_globals_group,

		//GRAPHICSPRESETDEFINITIONS_TAG = 'gfpd'
		&blofeld::infinite::GraphicsPresetDefinitions_group,

		//GAME_GLOBALS_GRENADE_LIST_TAG = 'gggl'
		&blofeld::infinite::game_globals_grenade_list_group,

		//HIGHLIGHTEVENTSGLOBALS_TAG = 'ghig'
		&blofeld::infinite::HighlightEventsGlobals_group,

		//CAMERAGLOBALSDEFINITION_TAG = 'glca'
		&blofeld::infinite::CameraGlobalsDefinition_group,

		//CHEATGLOBALSDEFINITION_TAG = 'glch'
		&blofeld::infinite::CheatGlobalsDefinition_group,

		//COMPOSERGLOBALSDEFINITION_TAG = 'glcm'
		&blofeld::infinite::ComposerGlobalsDefinition_group,

		//CONTROLGLOBALSDEFINITION_TAG = 'glcn'
		&blofeld::infinite::ControlGlobalsDefinition_group,

		//COLORGLOBALSDEFINITION_TAG = 'glco'
		&blofeld::infinite::ColorGlobalsDefinition_group,

		//DAMAGEGLOBALSDEFINITION_TAG = 'glda'
		&blofeld::infinite::DamageGlobalsDefinition_group,

		//CHEAP_LIGHT_TAG = 'gldf'
		&blofeld::infinite::cheap_light_group,

		//DIFFICULTYGLOBALSDEFINITION_TAG = 'gldi'
		&blofeld::infinite::DifficultyGlobalsDefinition_group,

		//GARBAGECOLLECTIONGLOBALSDEFINITION_TAG = 'glga'
		&blofeld::infinite::GarbageCollectionGlobalsDefinition_group,

		//GAMEPLAYOBJECTGLOBALSDEFINITION_TAG = 'glgo'
		&blofeld::infinite::GameplayObjectGlobalsDefinition_group,

		//INTERFACEGLOBALSDEFINITION_TAG = 'glin'
		&blofeld::infinite::InterfaceGlobalsDefinition_group,

		//LOCGLOBALSDEFINITION_TAG = 'gllo'
		&blofeld::infinite::LOCGlobalsDefinition_group,

		//MATERIALGLOBALSDEFINITION_TAG = 'glma'
		&blofeld::infinite::MaterialGlobalsDefinition_group,

		//PLAYERGLOBALSDEFINITION_TAG = 'glpa'
		&blofeld::infinite::PlayerGlobalsDefinition_group,

		//SKILLRANKINGGLOBALSDEFINITION_TAG = 'glsa'
		&blofeld::infinite::SkillRankingGlobalsDefinition_group,

		//SKULLGLOBALSDEFINITION_TAG = 'glsk'
		&blofeld::infinite::SkullGlobalsDefinition_group,

		//SOFTCEILINGGLOBALSDEFINITION_TAG = 'glso'
		&blofeld::infinite::SoftCeilingGlobalsDefinition_group,

		//SUBTITLEGLOBALSDEFINITION_TAG = 'glst'
		&blofeld::infinite::SubtitleGlobalsDefinition_group,

		//GAME_MEDAL_GLOBALS_TAG = 'gmeg'
		&blofeld::infinite::game_medal_globals_group,

		//GENERICMODIFIERDEFINITIONTAG_TAG = 'gmpm'
		&blofeld::infinite::GenericModifierDefinitionTag_group,

		//GAME_PERFORMANCE_THROTTLE_TAG = 'gptd'
		&blofeld::infinite::game_performance_throttle_group,

		//GROUNDED_FRICTION_TAG = 'grfr'
		&blofeld::infinite::grounded_friction_group,

		//GEOMETRY_TAG = 'gtag'
		&blofeld::infinite::geometry_group,

		//HAIR_TAG = 'hair'
		&blofeld::infinite::hair_group,

		//HLODSYSTEM_TAG = 'hlds'
		&blofeld::infinite::HlodSystem_group,

		//HLOD_METADATA_TAG = 'hlme'
		&blofeld::infinite::hlod_metadata_group,

		//HLODCUTOFFMATERIALLIST_TAG = 'hlml'
		&blofeld::infinite::hlodcutoffmateriallist_group,

		//MODEL_TAG = 'hlmt'
		&blofeld::infinite::model_group,

		//HLODPRESETS_TAG = 'hlpl'
		&blofeld::infinite::hlodpresets_group,

		//HLODSETTINGS_TAG = 'hlst'
		&blofeld::infinite::hlodsettings_group,

		//HOLOGRAM_LIGHTING_TAG = 'holt'
		&blofeld::infinite::hologram_lighting_group,

		//LUA_TAG = 'hsc*'
		&blofeld::infinite::lua_group,

		//SCRIPT_CONTAINER_TAG = 'hscn'
		&blofeld::infinite::script_container_group,

		//HIGHLIGHTSERVICEGLOBALSDEFINITION_TAG = 'hsgd'
		&blofeld::infinite::HighlightServiceGlobalsDefinition_group,

		//INGAMEMAPMATERIALVARIATIONS_TAG = 'immo'
		&blofeld::infinite::InGameMapMaterialVariations_group,

		//IMPOSTOR_TAG = 'impr'
		&blofeld::infinite::impostor_group,

		//INPUTBUNDLESET_TAG = 'inbs'
		&blofeld::infinite::InputBundleSet_group,

		//INPUTBUNDLE_TAG = 'inbu'
		&blofeld::infinite::InputBundle_group,

		//INPUTDEVICEBINDINGS_TAG = 'indb'
		&blofeld::infinite::InputDeviceBindings_group,

		//INPUTMODE_TAG = 'inmo'
		&blofeld::infinite::InputMode_group,

		//INPUTSCOPE_TAG = 'insc'
		&blofeld::infinite::InputScope_group,

		//INTERACTION_TAG = 'intr'
		&blofeld::infinite::interaction_group,

		//MODEL_ANIMATION_GRAPH_TAG = 'jmad'
		&blofeld::infinite::model_animation_graph_group,

		//DAMAGE_EFFECT_TAG = 'jpt!'
		&blofeld::infinite::damage_effect_group,

		//KITCOLLECTION_TAG = 'kcol'
		&blofeld::infinite::KitCollection_group,

		//KNOCKBACKRESPONSEOVERRIDESET_TAG = 'kros'
		&blofeld::infinite::knockbackresponseoverrideset_group,

		//LEGACYANIMSET_TAG = 'lani'
		&blofeld::infinite::LegacyAnimSet_group,

		//LENS_FLARE_TAG = 'lens'
		&blofeld::infinite::lens_flare_group,

		//LOADOUT_GLOBALS_DEFINITION_TAG = 'lgtd'
		&blofeld::infinite::loadout_globals_definition_group,

		//ANIMATIONLIBRARYAUDIO_TAG = 'lib1'
		&blofeld::infinite::AnimationLibraryAudio_group,

		//ANIMATIONLIBRARYFX_TAG = 'lib2'
		&blofeld::infinite::AnimationLibraryFx_group,

		//LIGHT_CONE_TAG = 'licn'
		&blofeld::infinite::light_cone_group,

		//LIGHT_TAG = 'ligh'
		&blofeld::infinite::light_group,

		//LIGHTGROUP_TAG = 'ligr'
		&blofeld::infinite::LightGroup_group,

		//LEVELOBJECTS_TAG = 'lobj'
		&blofeld::infinite::LevelObjects_group,

		//LOCATION_NAME_GLOBALS_DEFINITION_TAG = 'locs'
		&blofeld::infinite::location_name_globals_definition_group,

		//LODSETTINGS_TAG = 'lods'
		&blofeld::infinite::lodsettings_group,

		//LEVELSTATICGEO_TAG = 'lsgt'
		&blofeld::infinite::LevelStaticGeo_group,

		//SOUND_LOOPING_TAG = 'lsnd'
		&blofeld::infinite::sound_looping_group,

		//LEAF_SYSTEM_TAG = 'lswd'
		&blofeld::infinite::leaf_system_group,

		//UILIGHTPRESETS_TAG = 'ltps'
		&blofeld::infinite::UILightPresets_group,

		//LIGHT_VOLUME_SYSTEM_TAG = 'ltvl'
		&blofeld::infinite::light_volume_system_group,

		//LUA_SCRIPT_TAG = 'luas'
		&blofeld::infinite::lua_script_group,

		//INGAMEMAPRENDER_TAG = 'mapr'
		&blofeld::infinite::InGameMapRender_group,

		//INGAMEMAPSETTINGS_TAG = 'maps'
		&blofeld::infinite::InGameMapSettings_group,

		//MATERIAL_TAG = 'mat '
		&blofeld::infinite::material_group,

		//GLOBALS_TAG = 'matg'
		&blofeld::infinite::globals_group,

		//MATERIALPRESET_TAG = 'matp'
		&blofeld::infinite::MaterialPreset_group,

		//MODEL_DISSOLVE_DEFINITION_TAG = 'mdsv'
		&blofeld::infinite::model_dissolve_definition_group,

		//MELEEADDITIONALDAMAGE_TAG = 'mead'
		&blofeld::infinite::MeleeAdditionalDamage_group,

		//MELEEFRAMEATTACHMENT_TAG = 'mfat'
		&blofeld::infinite::MeleeFrameAttachment_group,

		//MATERIALEFFECTSGLOBALS_TAG = 'mfxg'
		&blofeld::infinite::materialeffectsglobals_group,

		//MELEEGLOBALS_TAG = 'mglb'
		&blofeld::infinite::MeleeGlobals_group,

		//RENDER_MODEL_TAG = 'mode'
		&blofeld::infinite::render_model_group,

		//MULTIPLAYER_OBJECT_TYPE_LIST_TAG = 'motl'
		&blofeld::infinite::multiplayer_object_type_list_group,

		//MARKER_TAG = 'mrkr'
		&blofeld::infinite::marker_group,

		//MOTIONTRACKERATTACHMENT_TAG = 'mtad'
		&blofeld::infinite::MotionTrackerAttachment_group,

		//MUSKETEER_TOE_DEFINITION_TAG_TAG = 'mtrd'
		&blofeld::infinite::musketeer_toe_definition_tag_group,

		//MULTIPLAYER_GLOBALS_TAG = 'mulg'
		&blofeld::infinite::multiplayer_globals_group,

		//MUSIC_CONTROL_TAG = 'musc'
		&blofeld::infinite::music_control_group,

		//MATERIALPALETTE_TAG = 'mwpl'
		&blofeld::infinite::MaterialPalette_group,

		//MATERIALSWATCH_TAG = 'mwsw'
		&blofeld::infinite::MaterialSwatch_group,

		//MATERIALSTYLES_TAG = 'mwsy'
		&blofeld::infinite::MaterialStyles_group,

		//MATERIALVISORSWATCH_TAG = 'mwvs'
		&blofeld::infinite::MaterialVisorSwatch_group,

		//NAVIGATIONGLOBALS_TAG = 'nagl'
		&blofeld::infinite::NavigationGlobals_group,

		//NARRATIVEGLOBALS_TAG = 'narg'
		&blofeld::infinite::NarrativeGlobals_group,

		//NAVPOINTANIMATIONDEFINITION_TAG = 'nava'
		&blofeld::infinite::NavPointAnimationDefinition_group,

		//NAVPOINTLAYOUTDEFINITION_TAG = 'navl'
		&blofeld::infinite::NavPointLayoutDefinition_group,

		//NAVPOINTPARAMETERSTAG_TAG = 'navp'
		&blofeld::infinite::NavPointParametersTag_group,

		//NODEGRAPH_TAG = 'ngfc'
		&blofeld::infinite::NodeGraph_group,

		//NODE_GRAPH_STACK_TAG = 'ngst'
		&blofeld::infinite::node_graph_stack_group,

		//CURVEDMALLEABLEPROPERTYTAG_TAG = 'nmpd'
		&blofeld::infinite::CurvedMalleablePropertyTag_group,

		//NARRATIVENODEGRAPH_TAG = 'nnct'
		&blofeld::infinite::NarrativeNodeGraph_group,

		//NARRATIONPHONEMES_TAG = 'nphg'
		&blofeld::infinite::NarrationPhonemes_group,

		//NAVPOINTANIMATIONGROUP_TAG = 'nvnm'
		&blofeld::infinite::NavPointAnimationGroup_group,

		//NAVPOINTPRESENTATION_TAG = 'nvpt'
		&blofeld::infinite::NavPointPresentation_group,

		//OBJECTATTACHMENTSDEFINITION_TAG = 'oatd'
		&blofeld::infinite::objectattachmentsdefinition_group,

		//OBJECTIVENODEGRAPH_TAG = 'obct'
		&blofeld::infinite::ObjectiveNodeGraph_group,

		//UIOBJECTCUSTOMIZATION_TAG = 'obcu'
		&blofeld::infinite::UIObjectCustomization_group,

		//OBJECT_TAG = 'obje'
		&blofeld::infinite::object_group,

		//CUSTOMIZATIONATTACHMENTCONFIGURATION_TAG = 'ocad'
		&blofeld::infinite::customizationattachmentconfiguration_group,

		//EFFECTOVERRIDE_TAG = 'oceo'
		&blofeld::infinite::EffectOverride_group,

		//OBJECT_CONFIGURATION_TAG = 'ocfg'
		&blofeld::infinite::object_configuration_group,

		//CUSTOMIZATIONGLOBALSDEFINITION_TAG = 'ocgd'
		&blofeld::infinite::customizationglobalsdefinition_group,

		//CUSTOMIZATIONTHEMECONFIGURATION_TAG = 'ocur'
		&blofeld::infinite::customizationthemeconfiguration_group,

		//CUSTOMIZATIONVEHICLETHEMECONFIGURATION_TAG = 'ocuv'
		&blofeld::infinite::customizationvehiclethemeconfiguration_group,

		//CUSTOMIZATIONWEAPONTHEMECONFIGURATION_TAG = 'ocuw'
		&blofeld::infinite::customizationweaponthemeconfiguration_group,

		//OBJECT_DISPENSER_COMPONENT_TAG = 'odis'
		&blofeld::infinite::object_dispenser_component_group,

		//DOCKINGSITEDEFINITION_TAG = 'odok'
		&blofeld::infinite::DockingSiteDefinition_group,

		//OBJECTNODEGRAPH_TAG = 'ongc'
		&blofeld::infinite::ObjectNodeGraph_group,

		//OBJECTNODEGRAPH_GLOBALS_TAG = 'ongg'
		&blofeld::infinite::objectnodegraph_globals_group,

		//OBJBHVTREENG_TAG = 'ongt'
		&blofeld::infinite::ObjBhvTreeNG_group,

		//OUTLINESERVICEGLOBALSDEFINITION_TAG = 'osgd'
		&blofeld::infinite::OutlineServiceGlobalsDefinition_group,

		//OUTLINETYPEDEFINITION_TAG = 'ostd'
		&blofeld::infinite::OutlineTypeDefinition_group,

		//PAINTERBRUSH_TAG = 'pabr'
		&blofeld::infinite::PainterBrush_group,

		//PARTICLEASSET_TAG = 'past'
		&blofeld::infinite::ParticleAsset_group,

		//PROPERTYBASEDEFFECTSTAG_TAG = 'pbfx'
		&blofeld::infinite::PropertyBasedEffectsTag_group,

		//PCA_ANIMATION_TAG = 'pcaa'
		&blofeld::infinite::pca_animation_group,

		//PARTICLE_EMITTER_CUSTOM_POINTS_TAG = 'pecp'
		&blofeld::infinite::particle_emitter_custom_points_group,

		//PERFORMANCE_THROTTLES_TAG = 'perf'
		&blofeld::infinite::performance_throttles_group,

		//PATHFINDING_TAG = 'pfnd'
		&blofeld::infinite::pathfinding_group,

		//CLAMBERINGDEFINITION_TAG = 'phcc'
		&blofeld::infinite::ClamberingDefinition_group,

		//PHYSICS_MODEL_TAG = 'phmo'
		&blofeld::infinite::physics_model_group,

		//PHYSICSGLOBALSDEFINITION_TAG = 'phyg'
		&blofeld::infinite::PhysicsGlobalsDefinition_group,

		//ASSET_PHYSICS_TAG = 'phys'
		&blofeld::infinite::asset_physics_group,

		//UIPLATFORMANIMATIONS_TAG = 'plan'
		&blofeld::infinite::UIPlatformAnimations_group,

		//LOWCEILINGCONTROLTAG_TAG = 'plcc'
		&blofeld::infinite::LowCeilingControlTag_group,

		//PLAYER_MODEL_CUSTOMIZATION_GLOBALS_TAG = 'pmcg'
		&blofeld::infinite::player_model_customization_globals_group,

		//PARTICLE_MODEL_TAG = 'pmdf'
		&blofeld::infinite::particle_model_group,

		//PARTICLE_PHYSICS_TAG = 'pmov'
		&blofeld::infinite::particle_physics_group,

		//PERSONALAIGLOBALSDEFINITION_TAG = 'pnai'
		&blofeld::infinite::PersonalAIGlobalsDefinition_group,

		//PHYSICS_PHANTOM_SOUNDS_TAG = 'pphs'
		&blofeld::infinite::physics_phantom_sounds_group,

		//POINT_PHYSICS_TAG = 'pphy'
		&blofeld::infinite::point_physics_group,

		//PREFAB_TAG = 'prfb'
		&blofeld::infinite::prefab_group,

		//PROJECTILEFLYBY_TAG = 'prjf'
		&blofeld::infinite::ProjectileFlyby_group,

		//PROJECTILEMATERIALRESPONSE_TAG = 'prmr'
		&blofeld::infinite::ProjectileMaterialResponse_group,

		//PROJECTILE_TAG = 'proj'
		&blofeld::infinite::projectile_group,

		//PROPSPAWNTEMPLATETAG_TAG = 'prpt'
		&blofeld::infinite::PropSpawnTemplateTag_group,

		//PARTICLE_TAG = 'prt3'
		&blofeld::infinite::particle_group,

		//PARTICLESHADERGRAPH_TAG = 'psct'
		&blofeld::infinite::ParticleShaderGraph_group,

		//PASSENGERCELLENTRYTAG_TAG = 'psgr'
		&blofeld::infinite::PassengerCellEntryTag_group,

		//PSODICTIONARY_TAG = 'psod'
		&blofeld::infinite::psoDictionary_group,

		//POWERUPDEFINITION_TAG = 'pugm'
		&blofeld::infinite::PowerupDefinition_group,

		//ZONESET_BAKED_PVS_TAG = 'pvsb'
		&blofeld::infinite::zoneset_baked_pvs_group,

		//RASTERIZER_GLOBALS_TAG = 'rasg'
		&blofeld::infinite::rasterizer_globals_group,

		//RENDERGRAPH_TAG = 'rgrf'
		&blofeld::infinite::RenderGraph_group,

		//RUMBLE_TAG = 'rmbl'
		&blofeld::infinite::rumble_group,

		//RENDERNODEGRAPH_TAG = 'rngr'
		&blofeld::infinite::RenderNodeGraph_group,

		//RUNTIME_SURFACING_TAG = 'rsrf'
		&blofeld::infinite::runtime_surfacing_group,

		//RUNTIME_GEO_TAG = 'rtgo'
		&blofeld::infinite::runtime_geo_group,

		//RUNTIMELAYER_TAG = 'rtlt'
		&blofeld::infinite::RuntimeLayer_group,

		//RTMP_TAG = 'rtmp'
		&blofeld::infinite::rtmp_group,

		//RUNTIME_TERRAIN_TAG = 'rtrn'
		&blofeld::infinite::runtime_terrain_group,

		//RENDER_WATER_RIPPLE_TAG = 'rwrd'
		&blofeld::infinite::render_water_ripple_group,

		//BOOSTJUMPDEFINITIONTAG_TAG = 'sabj'
		&blofeld::infinite::BoostJumpDefinitionTag_group,

		//SPRING_ACCELERATION_TAG = 'sadt'
		&blofeld::infinite::spring_acceleration_group,

		//EVADEDEFINITIONTAG_TAG = 'saev'
		&blofeld::infinite::EvadeDefinitionTag_group,

		//GRAPPLEHOOKDEFINITIONTAG_TAG = 'sagh'
		&blofeld::infinite::GrappleHookDefinitionTag_group,

		//GROUNDPOUNDDEFINITIONTAG_TAG = 'sagp'
		&blofeld::infinite::GroundPoundDefinitionTag_group,

		//UI_SAMPLE_DATA_TAG = 'samp'
		&blofeld::infinite::ui_sample_data_group,

		//SHOULDERBASHDEFINITIONTAG_TAG = 'sasb'
		&blofeld::infinite::ShoulderBashDefinitionTag_group,

		//SPRINTDEFINITIONTAG_TAG = 'sasp'
		&blofeld::infinite::SprintDefinitionTag_group,

		//STABILIZERDEFINITIONTAG_TAG = 'sast'
		&blofeld::infinite::StabilizerDefinitionTag_group,

		//TELEPORTDEFINITIONTAG_TAG = 'sate'
		&blofeld::infinite::TeleportDefinitionTag_group,

		//WALLCLINGDEFINITIONTAG_TAG = 'sawc'
		&blofeld::infinite::WallClingDefinitionTag_group,

		//WALLJUMPDEFINITIONTAG_TAG = 'sawj'
		&blofeld::infinite::WallJumpDefinitionTag_group,

		//BNK_TAG = 'sbdt'
		&blofeld::infinite::bnk_group,

		//SOUNDBANK_TAG = 'sbnk'
		&blofeld::infinite::soundbank_group,

		//SCENARIO_STRUCTURE_BSP_TAG = 'sbsp'
		&blofeld::infinite::scenario_structure_bsp_group,

		//SUPERCOMBINE_TAG = 'scbd'
		&blofeld::infinite::supercombine_group,

		//SCENERY_TAG = 'scen'
		&blofeld::infinite::scenery_group,

		//STATIC_COLLISION_TAG = 'scgt'
		&blofeld::infinite::static_collision_group,

		//STRUCTURE_DESIGN_TAG = 'sddt'
		&blofeld::infinite::structure_design_group,

		//SCENARIO_REQUIRED_RESOURCE_TAG = 'sdzg'
		&blofeld::infinite::scenario_required_resource_group,

		//AREA_SCREEN_EFFECT_TAG = 'sefc'
		&blofeld::infinite::area_screen_effect_group,

		//SURFACINGGRAPH_TAG = 'sgct'
		&blofeld::infinite::SurfacingGraph_group,

		//SPEECHGRAMMARGROUP_TAG = 'sggg'
		&blofeld::infinite::SpeechGrammarGroup_group,

		//SPEECHGRAMMARGLOBALS_TAG = 'sggs'
		&blofeld::infinite::SpeechGrammarGlobals_group,

		//SOUND_RESPONSE_TAG = 'sgrp'
		&blofeld::infinite::sound_response_group,

		//SHADER_BYTECODE_TAG = 'shbc'
		&blofeld::infinite::shader_bytecode_group,

		//SHADERVERSION_TAG = 'shd*'
		&blofeld::infinite::shaderversion_group,

		//BASESHADER_TAG = 'shdb'
		&blofeld::infinite::baseshader_group,

		//SHADEROPTIONS_TAG = 'shdo'
		&blofeld::infinite::shaderoptions_group,

		//SHADER_TAG = 'shdr'
		&blofeld::infinite::shader_group,

		//SHADERVARIANT_TAG = 'shdv'
		&blofeld::infinite::shadervariant_group,

		//SHADER_ROOT_SIGNATURE_TAG = 'shrs'
		&blofeld::infinite::shader_root_signature_group,

		//SHADERSUBGRAPH_TAG = 'shsg'
		&blofeld::infinite::ShaderSubGraph_group,

		//SELF_ILLUMINATION_TAG = 'sict'
		&blofeld::infinite::self_illumination_group,

		//SIMULATED_INPUT_TAG = 'sidt'
		&blofeld::infinite::simulated_input_group,

		//SUPPRESSEDINCIDENT_TAG = 'sigd'
		&blofeld::infinite::SuppressedIncident_group,

		//SIMULATION_INTERPOLATION_TAG = 'siin'
		&blofeld::infinite::simulation_interpolation_group,

		//SIMPLYGONSETTINGS_TAG = 'simp'
		&blofeld::infinite::simplygonsettings_group,

		//SOUND_INCIDENT_RESPONSE_TAG = 'sirg'
		&blofeld::infinite::sound_incident_response_group,

		//SCENARIO_INTERPOLATOR_TAG = 'sirp'
		&blofeld::infinite::scenario_interpolator_group,

		//SKELETON_TAG = 'skel'
		&blofeld::infinite::skeleton_group,

		//SKY_LIGHTING_TAG = 'sklt'
		&blofeld::infinite::sky_lighting_group,

		//SUPPLYLINESMARINESQUAD_TAG = 'slms'
		&blofeld::infinite::SupplyLinesMarineSquad_group,

		//SCENARIO_LIGHTING_VOLUMES_TAG = 'slvo'
		&blofeld::infinite::scenario_lighting_volumes_group,

		//SOUNDMATERIALEFFECTSDEFINITION_TAG = 'smed'
		&blofeld::infinite::SoundMaterialEffectsDefinition_group,

		//STRUCTURE_META_TAG = 'smet'
		&blofeld::infinite::structure_meta_group,

		//ACOUSTICSDATA_TAG = 'snad'
		&blofeld::infinite::AcousticsData_group,

		//SOUND_TAG = 'snd!'
		&blofeld::infinite::sound_group,

		//SOUND_CATEGORY_TAG = 'sndc'
		&blofeld::infinite::sound_category_group,

		//SOUND_ENVIRONMENT_TAG = 'snde'
		&blofeld::infinite::sound_environment_group,

		//SOUND_GLOBALS_TAG = 'sngl'
		&blofeld::infinite::sound_globals_group,

		//FRAMEATTACHMENTDEFINITION_TAG = 'sofa'
		&blofeld::infinite::FrameAttachmentDefinition_group,

		//FRAMEDEFINITION_TAG = 'sofd'
		&blofeld::infinite::FrameDefinition_group,

		//SPARTANABILITYCOMPONENTDEFINITION_TAG = 'spab'
		&blofeld::infinite::SpartanAbilityComponentDefinition_group,

		//SUPPLYLINESSYSTEMGLOBALSDEFINITION_TAG = 'spln'
		&blofeld::infinite::SupplyLinesSystemGlobalsDefinition_group,

		//SPARTANTRACKINGGLOBALSDEFINITION_TAG = 'sptg'
		&blofeld::infinite::SpartanTrackingGlobalsDefinition_group,

		//SPARTANTRACKINGPINGDEFINITION_TAG = 'sptp'
		&blofeld::infinite::SpartanTrackingPingDefinition_group,

		//SQUADSPECIFICATIONTAG_TAG = 'sqds'
		&blofeld::infinite::SquadSpecificationTag_group,

		//SQUAD_TEMPLATE_TAG = 'sqtm'
		&blofeld::infinite::squad_template_group,

		//SCENARIO_RENDER_DATA_TAG = 'sred'
		&blofeld::infinite::scenario_render_data_group,

		//SPAWNSETTINGS_TAG = 'ssdf'
		&blofeld::infinite::SpawnSettings_group,

		//SPOTTINGSERVICEGLOBALS_TAG = 'ssgd'
		&blofeld::infinite::SpottingServiceGlobals_group,

		//SSSPROFILE_TAG = 'sspg'
		&blofeld::infinite::sssProfile_group,

		//SCENARIO_SOUND_CONSTANTS_TAG = 'sssc'
		&blofeld::infinite::scenario_sound_constants_group,

		//SQUADSPECIFICATIONTREE_TAG = 'sstr'
		&blofeld::infinite::SquadSpecificationTree_group,

		//SOUND_TAIL_TAG = 'stai'
		&blofeld::infinite::sound_tail_group,

		//STRUCTURE_LIGHTMAP_TAG = 'stlm'
		&blofeld::infinite::structure_lightmap_group,

		//STRUCTURE_LIGHTS_TAG = 'strl'
		&blofeld::infinite::structure_lights_group,

		//STRUCTURE_SEAMS_TAG = 'stse'
		&blofeld::infinite::structure_seams_group,

		//STYLE_TAG = 'styl'
		&blofeld::infinite::style_group,

		//COMPOSER_SUBTRACKS_TAG = 'subt'
		&blofeld::infinite::composer_subtracks_group,

		//SHIELDUPGRADEMETADATA_TAG = 'sumd'
		&blofeld::infinite::ShieldUpgradeMetadata_group,

		//URI_LOOKUP_TABLE_TAG = 'suri'
		&blofeld::infinite::uri_lookup_table_group,

		//SVG_TAG = 'svg*'
		&blofeld::infinite::svg_group,

		//SWITCHABLEASSETSET_TAG = 'swas'
		&blofeld::infinite::SwitchableAssetSet_group,

		//TAGGRAPH_TAG = 'tagg'
		&blofeld::infinite::TagGraph_group,

		//TERRAIN_CELL_GEO_TAG = 'tccg'
		&blofeld::infinite::terrain_cell_geo_group,

		//TERRAIN_COLLISION_CGO_PARAMS_TAG = 'tcgp'
		&blofeld::infinite::terrain_collision_cgo_params_group,

		//TERRAIN_GEO_INPUTS_TAG = 'tcin'
		&blofeld::infinite::terrain_geo_inputs_group,

		//TERRAIN_GEO_INPUTS_SET_TAG = 'tcis'
		&blofeld::infinite::terrain_geo_inputs_set_group,

		//TEXTUREGROUP_TAG = 'texg'
		&blofeld::infinite::texturegroup_group,

		//STATERULESNODEGRAPH_TAG = 'tgct'
		&blofeld::infinite::StateRulesNodeGraph_group,

		//TIF_TAG = 'tif*'
		&blofeld::infinite::tif_group,

		//TRANSITIONLOGICGRAPH_TAG = 'tlct'
		&blofeld::infinite::TransitionLogicGraph_group,

		//XTRANSITIONLOGICGRAPH_TAG = 'tlgt'
		&blofeld::infinite::XTransitionLogicGraph_group,

		//TOKENSYSTEMGLOBALSDEFINITION_TAG = 'toks'
		&blofeld::infinite::TokenSystemGlobalsDefinition_group,

		//TRACER_SYSTEM_TAG = 'trac'
		&blofeld::infinite::tracer_system_group,

		//CAMERA_TRACK_TAG = 'trak'
		&blofeld::infinite::camera_track_group,

		//TERRAIN_COLLISION_GEO_TAG = 'trcg'
		&blofeld::infinite::terrain_collision_geo_group,

		//TRACKDECALSYSTEM_TAG = 'trds'
		&blofeld::infinite::TrackDecalSystem_group,

		//TERRAIN_INPUTS_TAG = 'trin'
		&blofeld::infinite::terrain_inputs_group,

		//TERRAIN_SYSTEM_TAG = 'trrn'
		&blofeld::infinite::terrain_system_group,

		//UITRANSITIONSOUNDS_TAG = 'trsd'
		&blofeld::infinite::UITransitionSounds_group,

		//TERRAIN_TILE_TAG = 'trtl'
		&blofeld::infinite::terrain_tile_group,

		//TERRAIN_SEED_FOR_MODULE_TAG = 'tsdm'
		&blofeld::infinite::terrain_seed_for_module_group,

		//TEST_TAG_TAG = 'ttag'
		&blofeld::infinite::test_tag_group,

		//TRIGGER_VOLUME_COMPONENT_TAG = 'tvcm'
		&blofeld::infinite::trigger_volume_component_group,

		//UCN_AUTHORITY_TRUST_SETTINGS_TAG = 'ucnt'
		&blofeld::infinite::ucn_authority_trust_settings_group,

		//DIALOGUE_TAG = 'udlg'
		&blofeld::infinite::dialogue_group,

		//UNITTESTNODEGRAPH_TAG = 'ugct'
		&blofeld::infinite::UnitTestNodeGraph_group,

		//GAMEPLAYMENUUIINFO_TAG = 'uigm'
		&blofeld::infinite::GameplayMenuUIInfo_group,

		//USER_INTERFACE_HUD_GLOBALS_DEFINITION_TAG = 'uihg'
		&blofeld::infinite::user_interface_hud_globals_definition_group,

		//UIITEMINSPECT_TAG = 'uiin'
		&blofeld::infinite::UIItemInspect_group,

		//USER_INTERFACE_SOUNDS_DEFINITION_TAG = 'uise'
		&blofeld::infinite::user_interface_sounds_definition_group,

		//UIVEHICLEDISPLAYINFODEFINITION_TAG = 'uivi'
		&blofeld::infinite::UIVehicleDisplayInfoDefinition_group,

		//UI_VEHICLE_NODE_DEFINITION_TAG = 'uivn'
		&blofeld::infinite::ui_vehicle_node_definition_group,

		//UIWEAPONDISPLAYINFODEFINITION_TAG = 'uiwi'
		&blofeld::infinite::UIWeaponDisplayInfoDefinition_group,

		//UI_ADS_WEAPON_NODE_DEFINITION_TAG = 'uiwn'
		&blofeld::infinite::ui_ads_weapon_node_definition_group,

		//MULTILINGUAL_UNICODE_STRING_LIST_TAG = 'unic'
		&blofeld::infinite::multilingual_unicode_string_list_group,

		//UNIT_TAG = 'unit'
		&blofeld::infinite::unit_group,

		//UNITRECORDINGDEFINITION_TAG = 'urcd'
		&blofeld::infinite::UnitRecordingDefinition_group,

		//STRINGLIST_TAG = 'uslg'
		&blofeld::infinite::stringList_group,

		//WEAPONFRAMEATTACHMENT_TAG = 'uwfa'
		&blofeld::infinite::WeaponFrameAttachment_group,

		//VALORUNLOCKS_TAG = 'valu'
		&blofeld::infinite::ValorUnlocks_group,

		//VECTORART_TAG = 'vart'
		&blofeld::infinite::VectorArt_group,

		//VEHICLEATTACHMENT_TAG = 'vatc'
		&blofeld::infinite::VehicleAttachment_group,

		//VEHICLECONFIGURATION_TAG = 'vcdd'
		&blofeld::infinite::VehicleConfiguration_group,

		//VEHICLE_TAG = 'vehi'
		&blofeld::infinite::vehicle_group,

		//VISUALMATERIALEFFECTSDEFINITION_TAG = 'vmed'
		&blofeld::infinite::VisualMaterialEffectsDefinition_group,

		//WEAPONCOMPONENTALTFIRE_TAG = 'walt'
		&blofeld::infinite::WeaponComponentAltFire_group,

		//WEAPON_CONFIGURATION_TAG = 'wcfg'
		&blofeld::infinite::weapon_configuration_group,

		//WEAPON_DEPTH_OF_FIELD_TAG = 'wdof'
		&blofeld::infinite::weapon_depth_of_field_group,

		//WEAPON_AIM_ASSIST_MODIFIERS_TAG = 'weaa'
		&blofeld::infinite::weapon_aim_assist_modifiers_group,

		//WEAPON_ATTACHMENT_BARREL_TAG = 'weab'
		&blofeld::infinite::weapon_attachment_barrel_group,

		//WEAPON_ATTACHMENT_HEAT_TAG = 'weah'
		&blofeld::infinite::weapon_attachment_heat_group,

		//WEAPON_ATTACHMENT_MAGAZINE_TAG = 'weam'
		&blofeld::infinite::weapon_attachment_magazine_group,

		//WEAPON_ATTACHMENT_TAG = 'weat'
		&blofeld::infinite::weapon_attachment_group,

		//WEAPON_ATTACHMENT_MELEE_TAG = 'weme'
		&blofeld::infinite::weapon_attachment_melee_group,

		//WEAPON_ATTACHMENT_SIGHT_TAG = 'west'
		&blofeld::infinite::weapon_attachment_sight_group,

		//WEAPON_ATTACHMENT_TRIGGER_TAG = 'wetr'
		&blofeld::infinite::weapon_attachment_trigger_group,

		//WEAPON_ATTACHMENT_TARGET_TRACKING_TAG = 'wett'
		&blofeld::infinite::weapon_attachment_target_tracking_group,

		//WEAPON_GLOBALS_TAG = 'wgbl'
		&blofeld::infinite::weapon_globals_group,

		//USER_INTERFACE_GLOBALS_DEFINITION_TAG = 'wgtz'
		&blofeld::infinite::user_interface_globals_definition_group,

		//USER_INTERFACE_SHARED_GLOBALS_DEFINITION_TAG = 'wigl'
		&blofeld::infinite::user_interface_shared_globals_definition_group,

		//WIND_TAG = 'wind'
		&blofeld::infinite::wind_group,

		//WATER_PHYSICS_DRAG_PROPERTIES_TAG = 'wpdp'
		&blofeld::infinite::water_physics_drag_properties_group,

		//XANIMBLENDGRAPHNG_TAG = 'xbgt'
		&blofeld::infinite::XAnimBlendGraphNG_group,

		//XMLTAG_TAG = 'xml*'
		&blofeld::infinite::xmltag_group,

		//XOBJECTNODEGRAPH_TAG = 'xong'
		&blofeld::infinite::XObjectNodeGraph_group,

		//GOBO_SETTING_TAG = 'GobS'
		&blofeld::infinite::gobo_setting_group,

		//LIGHTING_SETTINGS_TAG = 'LigS'
		&blofeld::infinite::lighting_settings_group,

		//RUNTIMEANIMSET_TAG = 'Rani'
		&blofeld::infinite::RuntimeAnimSet_group,

		//STREAMINGZONESET_TAG = 'SDzs'
		&blofeld::infinite::streamingzoneset_group,

		//ANIMNODEGRAPH_TAG = 'agct'
		&blofeld::infinite::AnimNodeGraph_group,

		//ANIMSTATENODEGRAPH_TAG = 'asct'
		&blofeld::infinite::AnimStateNodeGraph_group,

		//BLACKBOARDNODEGRAPH_TAG = 'bgct'
		&blofeld::infinite::BlackboardNodeGraph_group,

		//BIPED_TAG = 'bipd'
		&blofeld::infinite::biped_group,

		//CRATE_TAG = 'bloc'
		&blofeld::infinite::crate_group,

		//BLEND1DNODEGRAPH_TAG = 'boct'
		&blofeld::infinite::Blend1DNodeGraph_group,

		//BLENDRADIALNODEGRAPH_TAG = 'brct'
		&blofeld::infinite::BlendRadialNodeGraph_group,

		//BLEND2DNODEGRAPH_TAG = 'btct'
		&blofeld::infinite::Blend2DNodeGraph_group,

		//COMPOSITE_TAG = 'cpst'
		&blofeld::infinite::composite_group,

		//CREATURE_TAG = 'crea'
		&blofeld::infinite::creature_group,

		//DEVICE_TAG = 'devi'
		&blofeld::infinite::device_group,

		//DECORATORSHADERGRAPH_TAG = 'dsct'
		&blofeld::infinite::DecoratorShaderGraph_group,

		//DEVICE_DISPENSER_TAG = 'dspn'
		&blofeld::infinite::device_dispenser_group,

		//ENCOUNTERBEHAVIORTREEDEFINITION_TAG = 'ebtc'
		&blofeld::infinite::EncounterBehaviorTreeDefinition_group,

		//EFFECT_SCENERY_TAG = 'efsc'
		&blofeld::infinite::effect_scenery_group,

		//FORGEMENUGRAPH_TAG = 'fmct'
		&blofeld::infinite::ForgeMenuGraph_group,

		//FORGENODEGRAPH_TAG = 'fnct'
		&blofeld::infinite::ForgeNodeGraph_group,

		//GIANT_TAG = 'gint'
		&blofeld::infinite::giant_group,

		//ITEM_TAG = 'item'
		&blofeld::infinite::item_group,

		//KIT_TAG = 'kit!'
		&blofeld::infinite::kit_group,

		//LAYER_TAG = 'layr'
		&blofeld::infinite::layer_group,

		//LEVEL_TAG = 'levl'
		&blofeld::infinite::level_group,

		//LUANODEGRAPH_TAG = 'lgct'
		&blofeld::infinite::LuaNodeGraph_group,

		//DEVICE_MACHINE_TAG = 'mach'
		&blofeld::infinite::device_machine_group,

		//MATERIALSHADERGRAPH_TAG = 'msct'
		&blofeld::infinite::MaterialShaderGraph_group,

		//RAW_GEO_TAG = 'rawg'
		&blofeld::infinite::raw_geo_group,

		//DEVICE_TERMINAL_TAG = 'term'
		&blofeld::infinite::device_terminal_group,

		//ULEVEL_TAG = 'ulvl'
		&blofeld::infinite::ulevel_group,

		//WEAPON_TAG = 'weap'
		&blofeld::infinite::weapon_group,

		//DEVICE_CONTROL_TAG = 'ctrl'
		&blofeld::infinite::device_control_group,

		//EQUIPMENT_TAG = 'eqip'
		&blofeld::infinite::equipment_group,
		nullptr
	};

} // namespace blofeld
