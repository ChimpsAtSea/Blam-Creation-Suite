#include <haloinfinitetagdefinitions-private-pch.h>

namespace blofeld::haloinfinite::pc64::flight1
{
	s_tag_group const* const tag_groups[] =
	{
		//ANYTAG_TAG = 'aTag'
		&AnyTag_group,

		//AMBIENTACTIONPOINTDEFINITIONTAG_TAG = 'aaap'
		&AmbientActionPointDefinitionTag_group,

		//ABC_TAG = 'abc*'
		&abc_group,

		//ASSETCOLLECTION_TAG = 'acol'
		&AssetCollection_group,

		//ACTORCELLENTRYTAG_TAG = 'actc'
		&ActorCellEntryTag_group,

		//ASSET_DIALOGUE_TAG = 'adia'
		&asset_dialogue_group,

		//AI_DIALOGUE_GLOBALS_TAG = 'adlg'
		&ai_dialogue_globals_group,

		//AIRDROPSYSTEMGLOBALSDEFINITION_TAG = 'adrp'
		&AirDropSystemGlobalsDefinition_group,

		//AUTOHLODSETTINGS_TAG = 'ahld'
		&AutoHlodSettings_group,

		//AI_GLOBALS_TAG = 'aigl'
		&ai_globals_group,

		//ATTACHED_LIGHT_CONE_TAG = 'alic'
		&attached_light_cone_group,

		//ANIMATEDMESH_TAG = 'ames'
		&AnimatedMesh_group,

		//ANIMGLOBALS_TAG = 'angb'
		&animglobals_group,

		//XANIMNODEGRAPH_TAG = 'angt'
		&XAnimNodeGraph_group,

		//ANIMSET_TAG = 'anim'
		&AnimSet_group,

		//XANIMSTATEGRAPH_TAG = 'ansm'
		&XAnimStateGraph_group,

		//ANTENNA_TAG = 'ant!'
		&antenna_group,

		//ACTIONPRIORITYDATADEFINITIONTAG_TAG = 'apdd'
		&ActionPriorityDataDefinitionTag_group,

		//ASSET_TAG = 'aset'
		&asset_group,

		//ANIMATION_SKELETON_TAG = 'askt'
		&animation_skeleton_group,

		//ASSET_SOUND_TAG = 'asou'
		&asset_sound_group,

		//ASSET_CATEGORY_GLOBALS_TAG = 'atcg'
		&asset_category_globals_group,

		//ATMOSPHERE_GLOBALS_TAG = 'atgf'
		&atmosphere_globals_group,

		//ANIMTOKENGLOBALS_TAG = 'atkg'
		&AnimTokenGlobals_group,

		//AUDIOTHREATGLOBALS_TAG = 'attd'
		&AudioThreatGlobals_group,

		//DEATH_PROGRAM_SELECTOR_TAG = 'bdpd'
		&death_program_selector_group,

		//BEHAVIORTREE_TAG = 'beht'
		&BehaviorTree_group,

		//BINK_TAG = 'bink'
		&bink_group,

		//BITMAP_DICTIONARY_TAG = 'bitd'
		&bitmap_dictionary_group,

		//BITMAP_TAG = 'bitm'
		&bitmap_group,

		//BITMAP_USAGE_TABLE_TAG = 'biut'
		&bitmap_usage_table_group,

		//BSP_LIGHTING_VOLUMES_TAG = 'blvo'
		&bsp_lighting_volumes_group,

		//BENCHMARKDEFINITION_TAG = 'bnch'
		&BenchmarkDefinition_group,

		//UNITBOOSTDEFINITION_TAG = 'bost'
		&UnitBoostDefinition_group,

		//BOTGLOBALSTAG_TAG = 'botg'
		&BotGlobalsTag_group,

		//BITMAP_PACKAGE_SETTINGS_TAG = 'bpks'
		&bitmap_package_settings_group,

		//BSP_VOLUMES_TAG = 'bspv'
		&bsp_volumes_group,

		//CAGEDEFINITION_TAG = 'cage'
		&CageDefinition_group,

		//CAGEGLOBALSDEFINITION_TAG = 'cagg'
		&CageGlobalsDefinition_group,

		//CAMERA_ANIMATION_GRAPH_TAG = 'camg'
		&camera_animation_graph_group,

		//UICAMERAPRESETS_TAG = 'caps'
		&UICameraPresets_group,

		//COLLISION_DAMAGE_TAG = 'cddf'
		&collision_damage_group,

		//COLLISIONFILTERDEFINITION_TAG = 'cfdf'
		&CollisionFilterDefinition_group,

		//CAMERA_FX_SETTINGS_TAG = 'cfxs'
		&camera_fx_settings_group,

		//CHARACTER_TAG = 'char'
		&character_group,

		//CHROMA_DEFINITION_TAG = 'chrd'
		&chroma_definition_group,

		//CHROMA_TAG = 'chrm'
		&chroma_group,

		//COLLISIONLAYERAUDITCONFIGURATIONTAG_TAG = 'clac'
		&collisionLayerAuditConfigurationTag_group,

		//ANIMCLIP_TAG = 'clip'
		&animclip_group,

		//CLOTH_TAG = 'clwd'
		&cloth_group,

		//CAMO_TAG = 'cmoe'
		&camo_group,

		//CAMPAIGNGLOBALSDEFINITION_TAG = 'cmpg'
		&CampaignGlobalsDefinition_group,

		//COMPOSITION_SCENE_TAG = 'cmps'
		&composition_scene_group,

		//COMPOSER_TRANSITION_TAG = 'cmpt'
		&composer_transition_group,

		//CAMPAIGNUPGRADES_TAG = 'cmpu'
		&CampaignUpgrades_group,

		//CONTROLLER_MAPPING_TAG = 'cnmp'
		&controller_mapping_group,

		//CONVERSATION_TAG = 'cnvo'
		&Conversation_group,

		//CONVERSATIONTYPES_TAG = 'cnvt'
		&ConversationTypes_group,

		//COLLECTIBLESDEFINITION_TAG = 'cole'
		&CollectiblesDefinition_group,

		//COLLISION_MODEL_TAG = 'coll'
		&collision_model_group,

		//COLOR_TABLE_TAG = 'colo'
		&color_table_group,

		//CUSTOM_OBJECT_LIGHTING_TAG = 'colt'
		&custom_object_lighting_group,

		//COMPOSITION_TAG = 'comp'
		&composition_group,

		//CHEAP_PARTICLE_EMITTER_TAG = 'cpem'
		&cheap_particle_emitter_group,

		//CHEAP_PARTICLE_TYPE_LIBRARY_TAG = 'cptl'
		&cheap_particle_type_library_group,

		//CAMERA_SHAKE_TAG = 'csdt'
		&camera_shake_group,

		//CUI_RESOURCES_TAG = 'cure'
		&cui_resources_group,

		//CURVEDEFINITION_TAG = 'curv'
		&CurveDefinition_group,

		//CUI_SCREEN_TAG = 'cusc'
		&cui_screen_group,

		//CUI_STATIC_DATA_TAG = 'cust'
		&cui_static_data_group,

		//COATINGMATERIALSET_TAG = 'cwms'
		&CoatingMaterialSet_group,

		//DAMAGE_TAG = 'damg'
		&damage_group,

		//DECORATOR_ASSET_TAG = 'dcat'
		&decorator_asset_group,

		//DISPOSITIONCOLORS_TAG = 'dcgd'
		&dispositionColors_group,

		//DECORATOR_PALETTE_TAG = 'dcpt'
		&decorator_palette_group,

		//RUNTIME_DEC_TAG = 'dcrt'
		&runtime_dec_group,

		//DECORATOR_SETTINGS_TAG = 'dcst'
		&decorator_settings_group,

		//DECAL_SYSTEM_TAG = 'decs'
		&decal_system_group,

		//DAMAGE_EFFECT_SOUNDS_TAG = 'desd'
		&damage_effect_sounds_group,

		//DARKROOMASSEMBLY_TAG = 'dkam'
		&DarkRoomAssembly_group,

		//DARKROOMASSETSPEC_TAG = 'dkas'
		&DarkRoomAssetSpec_group,

		//DARKROOMCAMERASPEC_TAG = 'dkcs'
		&DarkRoomCameraSpec_group,

		//DARKROOMLIGHTINGSPEC_TAG = 'dkls'
		&DarkRoomLightingSpec_group,

		//DARKROOMANIMATIONSPEC_TAG = 'dkms'
		&DarkRoomAnimationSpec_group,

		//DARKROOMRENDERSETTINGSSPEC_TAG = 'dkrs'
		&DarkRoomRenderSettingsSpec_group,

		//DARKROOMSHOTLIST_TAG = 'dksl'
		&DarkRoomShotList_group,

		//DARKROOMSCREENSHOTSETTINGSSPEC_TAG = 'dkss'
		&DarkRoomScreenshotSettingsSpec_group,

		//DAMAGE_RESPONSE_DEFINITION_TAG = 'drdf'
		&damage_response_definition_group,

		//DAMAGEREPORTINGDISPLAYGLOBALS_TAG = 'drdg'
		&DamageReportingDisplayGlobals_group,

		//DIALOGUE_SYSTEM_DATA_TAG = 'dsdt'
		&dialogue_system_data_group,

		//DYNAMICWORLDSTATEGLOBALS_TAG = 'dwsg'
		&DynamicWorldStateGlobals_group,

		//EXPORTEDENCOUNTERBEHAVIORTREEDEFINITION_TAG = 'ebtt'
		&ExportedEncounterBehaviorTreeDefinition_group,

		//EFFECT_EXPOSURE_TAG = 'efex'
		&effect_exposure_group,

		//EFFECT_TAG = 'effe'
		&effect_group,

		//EFFECT_GLOBALS_TAG = 'effg'
		&effect_globals_group,

		//GENERATOR_SYSTEM_TAG = 'efge'
		&generator_system_group,

		//EFFECT_WIND_TAG = 'efwi'
		&effect_wind_group,

		//EFFECT_GLOBAL_FORCE_TAG = 'egfd'
		&effect_global_force_group,

		//EMBLEM_GLOBALS_TAG = 'embg'
		&emblem_globals_group,

		//EMBLEM_TAG = 'embl'
		&emblem_group,

		//EMBLEM_THEME_GLOBALS_TAG = 'emth'
		&emblem_theme_globals_group,

		//EMITTER_TAG = 'emtr'
		&emitter_group,

		//EXPLICITSHADERS_TAG = 'exs*'
		&explicitshaders_group,

		//EXPLICITSHADERTABLE_TAG = 'exst'
		&ExplicitShaderTable_group,

		//FORWARDFASTLIGHTING_TAG = 'fafl'
		&ForwardFastLighting_group,

		//FANFAREDEFINITION_TAG = 'fanf'
		&FanfareDefinition_group,

		//FIXEDDEPTHQUADTREE_TAG = 'fdqt'
		&FixedDepthQuadTree_group,

		//ANIMFRAMEEVENTS_TAG = 'fel0'
		&AnimFrameEvents_group,

		//ANIMFRAMEEVENTSAUDIO_TAG = 'fel1'
		&AnimFrameEventsAudio_group,

		//ANIMFRAMEEVENTSFX_TAG = 'fel2'
		&AnimFrameEventsFx_group,

		//ANIMFRAMEEVENTSAUDIO_V0_TAG = 'fel3'
		&AnimFrameEventsAudio_v0_group,

		//ANIMFRAMEEVENTSFX_V0_TAG = 'fel4'
		&AnimFrameEventsFx_v0_group,

		//FRAME_EVENT_LIST_AUDIO_TAG = 'fela'
		&frame_event_list_audio_group,

		//FRAME_EVENT_LIST_ANIM_TAG = 'felb'
		&frame_event_list_anim_group,

		//FRAME_EVENT_LIST_EFFECT_TAG = 'fele'
		&frame_event_list_effect_group,

		//FLOCK_TAG = 'flck'
		&flock_group,

		//FLINCH_IMPULSE_TAG = 'flni'
		&flinch_impulse_group,

		//FLINCH_SYSTEM_TAG = 'flns'
		&flinch_system_group,

		//FORGE_LOOPING_SOUND_CATEGORIES_TAG = 'flsc'
		&forge_looping_sound_categories_group,

		//TYPEFACE_TAG = 'fntf'
		&typeface_group,

		//FORGENAMEDTAGLISTS_TAG = 'fntl'
		&ForgeNamedTagLists_group,

		//WPF_FONT_SET_TAG = 'fnts'
		&wpf_font_set_group,

		//FOLIAGE_ASSET_TAG = 'foat'
		&foliage_asset_group,

		//ATMOSPHERE_FOG_TAG = 'fogg'
		&atmosphere_fog_group,

		//FORGEKIT_TAG = 'foki'
		&forgekit_group,

		//WPF_FONT_TAG = 'font'
		&wpf_font_group,

		//FORGEOBJECTDATA_TAG = 'food'
		&ForgeObjectData_group,

		//FORGEOBJECTMANIFEST_TAG = 'foom'
		&ForgeObjectManifest_group,

		//MATERIAL_EFFECTS_TAG = 'foot'
		&material_effects_group,

		//FORGE_SOUNDS_TAG = 'fora'
		&forge_sounds_group,

		//FORGE_GLOBALS_TAG = 'forg'
		&forge_globals_group,

		//FORMATION_TAG = 'form'
		&formation_group,

		//FORGEOBJECTSCRIPTPROPERTYMENUITEMDEFINITIONS_TAG = 'fosp'
		&ForgeObjectScriptPropertyMenuItemDefinitions_group,

		//FORGEPALETTEDEFINITION_TAG = 'fpal'
		&ForgePaletteDefinition_group,

		//FRAME_EVENT_LIST_TAG = 'frms'
		&frame_event_list_group,

		//FORGESOUNDLISTDEFINITION_TAG = 'fsld'
		&ForgeSoundListDefinition_group,

		//FORGE_SOUND_RESPONSE_SOUNDS_TAG = 'fsrs'
		&forge_sound_response_sounds_group,

		//FORGETELESCOPINGASSET_TAG = 'ftat'
		&ForgeTelescopingAsset_group,

		//COMPONENTDEFINITION_TAG = 'fuic'
		&ComponentDefinition_group,

		//SCREENDEFINITION_TAG = 'fuis'
		&ScreenDefinition_group,

		//EFFECTKIT_TAG = 'fxkt'
		&effectKit_group,

		//GAME_ENGINE_GLOBALS_TAG = 'gegl'
		&game_engine_globals_group,

		//GRAPHICSPRESETDEFINITIONS_TAG = 'gfpd'
		&GraphicsPresetDefinitions_group,

		//GAME_GLOBALS_GRENADE_LIST_TAG = 'gggl'
		&game_globals_grenade_list_group,

		//HIGHLIGHTEVENTSGLOBALS_TAG = 'ghig'
		&HighlightEventsGlobals_group,

		//CAMERAGLOBALSDEFINITION_TAG = 'glca'
		&CameraGlobalsDefinition_group,

		//CHEATGLOBALSDEFINITION_TAG = 'glch'
		&CheatGlobalsDefinition_group,

		//COMPOSERGLOBALSDEFINITION_TAG = 'glcm'
		&ComposerGlobalsDefinition_group,

		//CONTROLGLOBALSDEFINITION_TAG = 'glcn'
		&ControlGlobalsDefinition_group,

		//COLORGLOBALSDEFINITION_TAG = 'glco'
		&ColorGlobalsDefinition_group,

		//DAMAGEGLOBALSDEFINITION_TAG = 'glda'
		&DamageGlobalsDefinition_group,

		//CHEAP_LIGHT_TAG = 'gldf'
		&cheap_light_group,

		//DIFFICULTYGLOBALSDEFINITION_TAG = 'gldi'
		&DifficultyGlobalsDefinition_group,

		//GARBAGECOLLECTIONGLOBALSDEFINITION_TAG = 'glga'
		&GarbageCollectionGlobalsDefinition_group,

		//GAMEPLAYOBJECTGLOBALSDEFINITION_TAG = 'glgo'
		&GameplayObjectGlobalsDefinition_group,

		//INTERFACEGLOBALSDEFINITION_TAG = 'glin'
		&InterfaceGlobalsDefinition_group,

		//LOCGLOBALSDEFINITION_TAG = 'gllo'
		&LOCGlobalsDefinition_group,

		//MATERIALGLOBALSDEFINITION_TAG = 'glma'
		&MaterialGlobalsDefinition_group,

		//PLAYERGLOBALSDEFINITION_TAG = 'glpa'
		&PlayerGlobalsDefinition_group,

		//SKILLRANKINGGLOBALSDEFINITION_TAG = 'glsa'
		&SkillRankingGlobalsDefinition_group,

		//SKULLGLOBALSDEFINITION_TAG = 'glsk'
		&SkullGlobalsDefinition_group,

		//SOFTCEILINGGLOBALSDEFINITION_TAG = 'glso'
		&SoftCeilingGlobalsDefinition_group,

		//SUBTITLEGLOBALSDEFINITION_TAG = 'glst'
		&SubtitleGlobalsDefinition_group,

		//GAME_MEDAL_GLOBALS_TAG = 'gmeg'
		&game_medal_globals_group,

		//GENERICMODIFIERDEFINITIONTAG_TAG = 'gmpm'
		&GenericModifierDefinitionTag_group,

		//GAME_PERFORMANCE_THROTTLE_TAG = 'gptd'
		&game_performance_throttle_group,

		//GROUNDED_FRICTION_TAG = 'grfr'
		&grounded_friction_group,

		//GEOMETRY_TAG = 'gtag'
		&geometry_group,

		//HAIR_TAG = 'hair'
		&hair_group,

		//HLODSYSTEM_TAG = 'hlds'
		&HlodSystem_group,

		//HLOD_METADATA_TAG = 'hlme'
		&hlod_metadata_group,

		//HLODCUTOFFMATERIALLIST_TAG = 'hlml'
		&hlodcutoffmateriallist_group,

		//MODEL_TAG = 'hlmt'
		&model_group,

		//HLODPRESETS_TAG = 'hlpl'
		&hlodpresets_group,

		//HLODSETTINGS_TAG = 'hlst'
		&hlodsettings_group,

		//HOLOGRAM_LIGHTING_TAG = 'holt'
		&hologram_lighting_group,

		//LUA_TAG = 'hsc*'
		&lua_group,

		//SCRIPT_CONTAINER_TAG = 'hscn'
		&script_container_group,

		//HIGHLIGHTSERVICEGLOBALSDEFINITION_TAG = 'hsgd'
		&HighlightServiceGlobalsDefinition_group,

		//INGAMEMAPMATERIALVARIATIONS_TAG = 'immo'
		&InGameMapMaterialVariations_group,

		//IMPOSTOR_TAG = 'impr'
		&impostor_group,

		//INPUTBUNDLESET_TAG = 'inbs'
		&InputBundleSet_group,

		//INPUTBUNDLE_TAG = 'inbu'
		&InputBundle_group,

		//INPUTDEVICEBINDINGS_TAG = 'indb'
		&InputDeviceBindings_group,

		//INPUTMODE_TAG = 'inmo'
		&InputMode_group,

		//INPUTSCOPE_TAG = 'insc'
		&InputScope_group,

		//INTERACTION_TAG = 'intr'
		&interaction_group,

		//MODEL_ANIMATION_GRAPH_TAG = 'jmad'
		&model_animation_graph_group,

		//DAMAGE_EFFECT_TAG = 'jpt!'
		&damage_effect_group,

		//KITCOLLECTION_TAG = 'kcol'
		&KitCollection_group,

		//KNOCKBACKRESPONSEOVERRIDESET_TAG = 'kros'
		&knockbackresponseoverrideset_group,

		//LEGACYANIMSET_TAG = 'lani'
		&LegacyAnimSet_group,

		//LENS_FLARE_TAG = 'lens'
		&lens_flare_group,

		//LOADOUT_GLOBALS_DEFINITION_TAG = 'lgtd'
		&loadout_globals_definition_group,

		//ANIMATIONLIBRARYAUDIO_TAG = 'lib1'
		&AnimationLibraryAudio_group,

		//ANIMATIONLIBRARYFX_TAG = 'lib2'
		&AnimationLibraryFx_group,

		//LIGHT_CONE_TAG = 'licn'
		&light_cone_group,

		//LIGHT_TAG = 'ligh'
		&light_group,

		//LIGHTGROUP_TAG = 'ligr'
		&LightGroup_group,

		//LEVELOBJECTS_TAG = 'lobj'
		&LevelObjects_group,

		//LOCATION_NAME_GLOBALS_DEFINITION_TAG = 'locs'
		&location_name_globals_definition_group,

		//LODSETTINGS_TAG = 'lods'
		&lodsettings_group,

		//LEVELSTATICGEO_TAG = 'lsgt'
		&LevelStaticGeo_group,

		//SOUND_LOOPING_TAG = 'lsnd'
		&sound_looping_group,

		//LEAF_SYSTEM_TAG = 'lswd'
		&leaf_system_group,

		//UILIGHTPRESETS_TAG = 'ltps'
		&UILightPresets_group,

		//LIGHT_VOLUME_SYSTEM_TAG = 'ltvl'
		&light_volume_system_group,

		//LUA_SCRIPT_TAG = 'luas'
		&lua_script_group,

		//INGAMEMAPRENDER_TAG = 'mapr'
		&InGameMapRender_group,

		//INGAMEMAPSETTINGS_TAG = 'maps'
		&InGameMapSettings_group,

		//MATERIAL_TAG = 'mat '
		&material_group,

		//GLOBALS_TAG = 'matg'
		&globals_group,

		//MATERIALPRESET_TAG = 'matp'
		&MaterialPreset_group,

		//MODEL_DISSOLVE_DEFINITION_TAG = 'mdsv'
		&model_dissolve_definition_group,

		//MELEEADDITIONALDAMAGE_TAG = 'mead'
		&MeleeAdditionalDamage_group,

		//MELEEFRAMEATTACHMENT_TAG = 'mfat'
		&MeleeFrameAttachment_group,

		//MATERIALEFFECTSGLOBALS_TAG = 'mfxg'
		&materialeffectsglobals_group,

		//MELEEGLOBALS_TAG = 'mglb'
		&MeleeGlobals_group,

		//RENDER_MODEL_TAG = 'mode'
		&render_model_group,

		//MULTIPLAYER_OBJECT_TYPE_LIST_TAG = 'motl'
		&multiplayer_object_type_list_group,

		//MARKER_TAG = 'mrkr'
		&marker_group,

		//MOTIONTRACKERATTACHMENT_TAG = 'mtad'
		&MotionTrackerAttachment_group,

		//MUSKETEER_TOE_DEFINITION_TAG_TAG = 'mtrd'
		&musketeer_toe_definition_tag_group,

		//MULTIPLAYER_GLOBALS_TAG = 'mulg'
		&multiplayer_globals_group,

		//MUSIC_CONTROL_TAG = 'musc'
		&music_control_group,

		//MATERIALPALETTE_TAG = 'mwpl'
		&MaterialPalette_group,

		//MATERIALSWATCH_TAG = 'mwsw'
		&MaterialSwatch_group,

		//MATERIALSTYLES_TAG = 'mwsy'
		&MaterialStyles_group,

		//MATERIALVISORSWATCH_TAG = 'mwvs'
		&MaterialVisorSwatch_group,

		//NAVIGATIONGLOBALS_TAG = 'nagl'
		&NavigationGlobals_group,

		//NARRATIVEGLOBALS_TAG = 'narg'
		&NarrativeGlobals_group,

		//NAVPOINTANIMATIONDEFINITION_TAG = 'nava'
		&NavPointAnimationDefinition_group,

		//NAVPOINTLAYOUTDEFINITION_TAG = 'navl'
		&NavPointLayoutDefinition_group,

		//NAVPOINTPARAMETERSTAG_TAG = 'navp'
		&NavPointParametersTag_group,

		//NODEGRAPH_TAG = 'ngfc'
		&NodeGraph_group,

		//NODE_GRAPH_STACK_TAG = 'ngst'
		&node_graph_stack_group,

		//CURVEDMALLEABLEPROPERTYTAG_TAG = 'nmpd'
		&CurvedMalleablePropertyTag_group,

		//NARRATIVENODEGRAPH_TAG = 'nnct'
		&NarrativeNodeGraph_group,

		//NARRATIONPHONEMES_TAG = 'nphg'
		&NarrationPhonemes_group,

		//NAVPOINTANIMATIONGROUP_TAG = 'nvnm'
		&NavPointAnimationGroup_group,

		//NAVPOINTPRESENTATION_TAG = 'nvpt'
		&NavPointPresentation_group,

		//OBJECTATTACHMENTSDEFINITION_TAG = 'oatd'
		&objectattachmentsdefinition_group,

		//OBJECTIVENODEGRAPH_TAG = 'obct'
		&ObjectiveNodeGraph_group,

		//UIOBJECTCUSTOMIZATION_TAG = 'obcu'
		&UIObjectCustomization_group,

		//OBJECT_TAG = 'obje'
		&object_group,

		//CUSTOMIZATIONATTACHMENTCONFIGURATION_TAG = 'ocad'
		&customizationattachmentconfiguration_group,

		//EFFECTOVERRIDE_TAG = 'oceo'
		&EffectOverride_group,

		//OBJECT_CONFIGURATION_TAG = 'ocfg'
		&object_configuration_group,

		//CUSTOMIZATIONGLOBALSDEFINITION_TAG = 'ocgd'
		&customizationglobalsdefinition_group,

		//CUSTOMIZATIONTHEMECONFIGURATION_TAG = 'ocur'
		&customizationthemeconfiguration_group,

		//CUSTOMIZATIONVEHICLETHEMECONFIGURATION_TAG = 'ocuv'
		&customizationvehiclethemeconfiguration_group,

		//CUSTOMIZATIONWEAPONTHEMECONFIGURATION_TAG = 'ocuw'
		&customizationweaponthemeconfiguration_group,

		//OBJECT_DISPENSER_COMPONENT_TAG = 'odis'
		&object_dispenser_component_group,

		//DOCKINGSITEDEFINITION_TAG = 'odok'
		&DockingSiteDefinition_group,

		//OBJECTNODEGRAPH_TAG = 'ongc'
		&ObjectNodeGraph_group,

		//OBJECTNODEGRAPH_GLOBALS_TAG = 'ongg'
		&objectnodegraph_globals_group,

		//OBJBHVTREENG_TAG = 'ongt'
		&ObjBhvTreeNG_group,

		//OUTLINESERVICEGLOBALSDEFINITION_TAG = 'osgd'
		&OutlineServiceGlobalsDefinition_group,

		//OUTLINETYPEDEFINITION_TAG = 'ostd'
		&OutlineTypeDefinition_group,

		//PAINTERBRUSH_TAG = 'pabr'
		&PainterBrush_group,

		//PARTICLEASSET_TAG = 'past'
		&ParticleAsset_group,

		//PROPERTYBASEDEFFECTSTAG_TAG = 'pbfx'
		&PropertyBasedEffectsTag_group,

		//PCA_ANIMATION_TAG = 'pcaa'
		&pca_animation_group,

		//PARTICLE_EMITTER_CUSTOM_POINTS_TAG = 'pecp'
		&particle_emitter_custom_points_group,

		//PERFORMANCE_THROTTLES_TAG = 'perf'
		&performance_throttles_group,

		//PATHFINDING_TAG = 'pfnd'
		&pathfinding_group,

		//CLAMBERINGDEFINITION_TAG = 'phcc'
		&ClamberingDefinition_group,

		//PHYSICS_MODEL_TAG = 'phmo'
		&physics_model_group,

		//PHYSICSGLOBALSDEFINITION_TAG = 'phyg'
		&PhysicsGlobalsDefinition_group,

		//ASSET_PHYSICS_TAG = 'phys'
		&asset_physics_group,

		//UIPLATFORMANIMATIONS_TAG = 'plan'
		&UIPlatformAnimations_group,

		//LOWCEILINGCONTROLTAG_TAG = 'plcc'
		&LowCeilingControlTag_group,

		//PLAYER_MODEL_CUSTOMIZATION_GLOBALS_TAG = 'pmcg'
		&player_model_customization_globals_group,

		//PARTICLE_MODEL_TAG = 'pmdf'
		&particle_model_group,

		//PARTICLE_PHYSICS_TAG = 'pmov'
		&particle_physics_group,

		//PERSONALAIGLOBALSDEFINITION_TAG = 'pnai'
		&PersonalAIGlobalsDefinition_group,

		//PHYSICS_PHANTOM_SOUNDS_TAG = 'pphs'
		&physics_phantom_sounds_group,

		//POINT_PHYSICS_TAG = 'pphy'
		&point_physics_group,

		//PREFAB_TAG = 'prfb'
		&prefab_group,

		//PROJECTILEFLYBY_TAG = 'prjf'
		&ProjectileFlyby_group,

		//PROJECTILEMATERIALRESPONSE_TAG = 'prmr'
		&ProjectileMaterialResponse_group,

		//PROJECTILE_TAG = 'proj'
		&projectile_group,

		//PROPSPAWNTEMPLATETAG_TAG = 'prpt'
		&PropSpawnTemplateTag_group,

		//PARTICLE_TAG = 'prt3'
		&particle_group,

		//PARTICLESHADERGRAPH_TAG = 'psct'
		&ParticleShaderGraph_group,

		//PASSENGERCELLENTRYTAG_TAG = 'psgr'
		&PassengerCellEntryTag_group,

		//PSODICTIONARY_TAG = 'psod'
		&psoDictionary_group,

		//POWERUPDEFINITION_TAG = 'pugm'
		&PowerupDefinition_group,

		//ZONESET_BAKED_PVS_TAG = 'pvsb'
		&zoneset_baked_pvs_group,

		//RASTERIZER_GLOBALS_TAG = 'rasg'
		&rasterizer_globals_group,

		//RENDERGRAPH_TAG = 'rgrf'
		&RenderGraph_group,

		//RUMBLE_TAG = 'rmbl'
		&rumble_group,

		//RENDERNODEGRAPH_TAG = 'rngr'
		&RenderNodeGraph_group,

		//RUNTIME_SURFACING_TAG = 'rsrf'
		&runtime_surfacing_group,

		//RUNTIME_GEO_TAG = 'rtgo'
		&runtime_geo_group,

		//RUNTIMELAYER_TAG = 'rtlt'
		&RuntimeLayer_group,

		//RTMP_TAG = 'rtmp'
		&rtmp_group,

		//RUNTIME_TERRAIN_TAG = 'rtrn'
		&runtime_terrain_group,

		//RENDER_WATER_RIPPLE_TAG = 'rwrd'
		&render_water_ripple_group,

		//BOOSTJUMPDEFINITIONTAG_TAG = 'sabj'
		&BoostJumpDefinitionTag_group,

		//SPRING_ACCELERATION_TAG = 'sadt'
		&spring_acceleration_group,

		//EVADEDEFINITIONTAG_TAG = 'saev'
		&EvadeDefinitionTag_group,

		//GRAPPLEHOOKDEFINITIONTAG_TAG = 'sagh'
		&GrappleHookDefinitionTag_group,

		//GROUNDPOUNDDEFINITIONTAG_TAG = 'sagp'
		&GroundPoundDefinitionTag_group,

		//UI_SAMPLE_DATA_TAG = 'samp'
		&ui_sample_data_group,

		//SHOULDERBASHDEFINITIONTAG_TAG = 'sasb'
		&ShoulderBashDefinitionTag_group,

		//SPRINTDEFINITIONTAG_TAG = 'sasp'
		&SprintDefinitionTag_group,

		//STABILIZERDEFINITIONTAG_TAG = 'sast'
		&StabilizerDefinitionTag_group,

		//TELEPORTDEFINITIONTAG_TAG = 'sate'
		&TeleportDefinitionTag_group,

		//WALLCLINGDEFINITIONTAG_TAG = 'sawc'
		&WallClingDefinitionTag_group,

		//WALLJUMPDEFINITIONTAG_TAG = 'sawj'
		&WallJumpDefinitionTag_group,

		//BNK_TAG = 'sbdt'
		&bnk_group,

		//SOUNDBANK_TAG = 'sbnk'
		&soundbank_group,

		//SCENARIO_STRUCTURE_BSP_TAG = 'sbsp'
		&scenario_structure_bsp_group,

		//SUPERCOMBINE_TAG = 'scbd'
		&supercombine_group,

		//SCENERY_TAG = 'scen'
		&scenery_group,

		//STATIC_COLLISION_TAG = 'scgt'
		&static_collision_group,

		//STRUCTURE_DESIGN_TAG = 'sddt'
		&structure_design_group,

		//SCENARIO_REQUIRED_RESOURCE_TAG = 'sdzg'
		&scenario_required_resource_group,

		//AREA_SCREEN_EFFECT_TAG = 'sefc'
		&area_screen_effect_group,

		//SURFACINGGRAPH_TAG = 'sgct'
		&SurfacingGraph_group,

		//SPEECHGRAMMARGROUP_TAG = 'sggg'
		&SpeechGrammarGroup_group,

		//SPEECHGRAMMARGLOBALS_TAG = 'sggs'
		&SpeechGrammarGlobals_group,

		//SOUND_RESPONSE_TAG = 'sgrp'
		&sound_response_group,

		//SHADER_BYTECODE_TAG = 'shbc'
		&shader_bytecode_group,

		//SHADERVERSION_TAG = 'shd*'
		&shaderversion_group,

		//BASESHADER_TAG = 'shdb'
		&baseshader_group,

		//SHADEROPTIONS_TAG = 'shdo'
		&shaderoptions_group,

		//SHADER_TAG = 'shdr'
		&shader_group,

		//SHADERVARIANT_TAG = 'shdv'
		&shadervariant_group,

		//SHADER_ROOT_SIGNATURE_TAG = 'shrs'
		&shader_root_signature_group,

		//SHADERSUBGRAPH_TAG = 'shsg'
		&ShaderSubGraph_group,

		//SELF_ILLUMINATION_TAG = 'sict'
		&self_illumination_group,

		//SIMULATED_INPUT_TAG = 'sidt'
		&simulated_input_group,

		//SUPPRESSEDINCIDENT_TAG = 'sigd'
		&SuppressedIncident_group,

		//SIMULATION_INTERPOLATION_TAG = 'siin'
		&simulation_interpolation_group,

		//SIMPLYGONSETTINGS_TAG = 'simp'
		&simplygonsettings_group,

		//SOUND_INCIDENT_RESPONSE_TAG = 'sirg'
		&sound_incident_response_group,

		//SCENARIO_INTERPOLATOR_TAG = 'sirp'
		&scenario_interpolator_group,

		//SKELETON_TAG = 'skel'
		&skeleton_group,

		//SKY_LIGHTING_TAG = 'sklt'
		&sky_lighting_group,

		//SUPPLYLINESMARINESQUAD_TAG = 'slms'
		&SupplyLinesMarineSquad_group,

		//SCENARIO_LIGHTING_VOLUMES_TAG = 'slvo'
		&scenario_lighting_volumes_group,

		//SOUNDMATERIALEFFECTSDEFINITION_TAG = 'smed'
		&SoundMaterialEffectsDefinition_group,

		//STRUCTURE_META_TAG = 'smet'
		&structure_meta_group,

		//ACOUSTICSDATA_TAG = 'snad'
		&AcousticsData_group,

		//SOUND_TAG = 'snd!'
		&sound_group,

		//SOUND_CATEGORY_TAG = 'sndc'
		&sound_category_group,

		//SOUND_ENVIRONMENT_TAG = 'snde'
		&sound_environment_group,

		//SOUND_GLOBALS_TAG = 'sngl'
		&sound_globals_group,

		//FRAMEATTACHMENTDEFINITION_TAG = 'sofa'
		&FrameAttachmentDefinition_group,

		//FRAMEDEFINITION_TAG = 'sofd'
		&FrameDefinition_group,

		//SPARTANABILITYCOMPONENTDEFINITION_TAG = 'spab'
		&SpartanAbilityComponentDefinition_group,

		//SUPPLYLINESSYSTEMGLOBALSDEFINITION_TAG = 'spln'
		&SupplyLinesSystemGlobalsDefinition_group,

		//SPARTANTRACKINGGLOBALSDEFINITION_TAG = 'sptg'
		&SpartanTrackingGlobalsDefinition_group,

		//SPARTANTRACKINGPINGDEFINITION_TAG = 'sptp'
		&SpartanTrackingPingDefinition_group,

		//SQUADSPECIFICATIONTAG_TAG = 'sqds'
		&SquadSpecificationTag_group,

		//SQUAD_TEMPLATE_TAG = 'sqtm'
		&squad_template_group,

		//SCENARIO_RENDER_DATA_TAG = 'sred'
		&scenario_render_data_group,

		//SPAWNSETTINGS_TAG = 'ssdf'
		&SpawnSettings_group,

		//SPOTTINGSERVICEGLOBALS_TAG = 'ssgd'
		&SpottingServiceGlobals_group,

		//SSSPROFILE_TAG = 'sspg'
		&sssProfile_group,

		//SCENARIO_SOUND_CONSTANTS_TAG = 'sssc'
		&scenario_sound_constants_group,

		//SQUADSPECIFICATIONTREE_TAG = 'sstr'
		&SquadSpecificationTree_group,

		//SOUND_TAIL_TAG = 'stai'
		&sound_tail_group,

		//STRUCTURE_LIGHTMAP_TAG = 'stlm'
		&structure_lightmap_group,

		//STRUCTURE_LIGHTS_TAG = 'strl'
		&structure_lights_group,

		//STRUCTURE_SEAMS_TAG = 'stse'
		&structure_seams_group,

		//STYLE_TAG = 'styl'
		&style_group,

		//COMPOSER_SUBTRACKS_TAG = 'subt'
		&composer_subtracks_group,

		//SHIELDUPGRADEMETADATA_TAG = 'sumd'
		&ShieldUpgradeMetadata_group,

		//URI_LOOKUP_TABLE_TAG = 'suri'
		&uri_lookup_table_group,

		//SVG_TAG = 'svg*'
		&svg_group,

		//SWITCHABLEASSETSET_TAG = 'swas'
		&SwitchableAssetSet_group,

		//TAGGRAPH_TAG = 'tagg'
		&TagGraph_group,

		//TERRAIN_CELL_GEO_TAG = 'tccg'
		&terrain_cell_geo_group,

		//TERRAIN_COLLISION_CGO_PARAMS_TAG = 'tcgp'
		&terrain_collision_cgo_params_group,

		//TERRAIN_GEO_INPUTS_TAG = 'tcin'
		&terrain_geo_inputs_group,

		//TERRAIN_GEO_INPUTS_SET_TAG = 'tcis'
		&terrain_geo_inputs_set_group,

		//TEXTUREGROUP_TAG = 'texg'
		&texturegroup_group,

		//STATERULESNODEGRAPH_TAG = 'tgct'
		&StateRulesNodeGraph_group,

		//TIF_TAG = 'tif*'
		&tif_group,

		//TRANSITIONLOGICGRAPH_TAG = 'tlct'
		&TransitionLogicGraph_group,

		//XTRANSITIONLOGICGRAPH_TAG = 'tlgt'
		&XTransitionLogicGraph_group,

		//TOKENSYSTEMGLOBALSDEFINITION_TAG = 'toks'
		&TokenSystemGlobalsDefinition_group,

		//TRACER_SYSTEM_TAG = 'trac'
		&tracer_system_group,

		//CAMERA_TRACK_TAG = 'trak'
		&camera_track_group,

		//TERRAIN_COLLISION_GEO_TAG = 'trcg'
		&terrain_collision_geo_group,

		//TRACKDECALSYSTEM_TAG = 'trds'
		&TrackDecalSystem_group,

		//TERRAIN_INPUTS_TAG = 'trin'
		&terrain_inputs_group,

		//TERRAIN_SYSTEM_TAG = 'trrn'
		&terrain_system_group,

		//UITRANSITIONSOUNDS_TAG = 'trsd'
		&UITransitionSounds_group,

		//TERRAIN_TILE_TAG = 'trtl'
		&terrain_tile_group,

		//TERRAIN_SEED_FOR_MODULE_TAG = 'tsdm'
		&terrain_seed_for_module_group,

		//TEST_TAG_TAG = 'ttag'
		&test_tag_group,

		//TRIGGER_VOLUME_COMPONENT_TAG = 'tvcm'
		&trigger_volume_component_group,

		//UCN_AUTHORITY_TRUST_SETTINGS_TAG = 'ucnt'
		&ucn_authority_trust_settings_group,

		//DIALOGUE_TAG = 'udlg'
		&dialogue_group,

		//UNITTESTNODEGRAPH_TAG = 'ugct'
		&UnitTestNodeGraph_group,

		//GAMEPLAYMENUUIINFO_TAG = 'uigm'
		&GameplayMenuUIInfo_group,

		//USER_INTERFACE_HUD_GLOBALS_DEFINITION_TAG = 'uihg'
		&user_interface_hud_globals_definition_group,

		//UIITEMINSPECT_TAG = 'uiin'
		&UIItemInspect_group,

		//USER_INTERFACE_SOUNDS_DEFINITION_TAG = 'uise'
		&user_interface_sounds_definition_group,

		//UIVEHICLEDISPLAYINFODEFINITION_TAG = 'uivi'
		&UIVehicleDisplayInfoDefinition_group,

		//UI_VEHICLE_NODE_DEFINITION_TAG = 'uivn'
		&ui_vehicle_node_definition_group,

		//UIWEAPONDISPLAYINFODEFINITION_TAG = 'uiwi'
		&UIWeaponDisplayInfoDefinition_group,

		//UI_ADS_WEAPON_NODE_DEFINITION_TAG = 'uiwn'
		&ui_ads_weapon_node_definition_group,

		//MULTILINGUAL_UNICODE_STRING_LIST_TAG = 'unic'
		&multilingual_unicode_string_list_group,

		//UNIT_TAG = 'unit'
		&unit_group,

		//UNITRECORDINGDEFINITION_TAG = 'urcd'
		&UnitRecordingDefinition_group,

		//STRINGLIST_TAG = 'uslg'
		&stringList_group,

		//WEAPONFRAMEATTACHMENT_TAG = 'uwfa'
		&WeaponFrameAttachment_group,

		//VALORUNLOCKS_TAG = 'valu'
		&ValorUnlocks_group,

		//VECTORART_TAG = 'vart'
		&VectorArt_group,

		//VEHICLEATTACHMENT_TAG = 'vatc'
		&VehicleAttachment_group,

		//VEHICLECONFIGURATION_TAG = 'vcdd'
		&VehicleConfiguration_group,

		//VEHICLE_TAG = 'vehi'
		&vehicle_group,

		//VISUALMATERIALEFFECTSDEFINITION_TAG = 'vmed'
		&VisualMaterialEffectsDefinition_group,

		//WEAPONCOMPONENTALTFIRE_TAG = 'walt'
		&WeaponComponentAltFire_group,

		//WEAPON_CONFIGURATION_TAG = 'wcfg'
		&weapon_configuration_group,

		//WEAPON_DEPTH_OF_FIELD_TAG = 'wdof'
		&weapon_depth_of_field_group,

		//WEAPON_AIM_ASSIST_MODIFIERS_TAG = 'weaa'
		&weapon_aim_assist_modifiers_group,

		//WEAPON_ATTACHMENT_BARREL_TAG = 'weab'
		&weapon_attachment_barrel_group,

		//WEAPON_ATTACHMENT_HEAT_TAG = 'weah'
		&weapon_attachment_heat_group,

		//WEAPON_ATTACHMENT_MAGAZINE_TAG = 'weam'
		&weapon_attachment_magazine_group,

		//WEAPON_ATTACHMENT_TAG = 'weat'
		&weapon_attachment_group,

		//WEAPON_ATTACHMENT_MELEE_TAG = 'weme'
		&weapon_attachment_melee_group,

		//WEAPON_ATTACHMENT_SIGHT_TAG = 'west'
		&weapon_attachment_sight_group,

		//WEAPON_ATTACHMENT_TRIGGER_TAG = 'wetr'
		&weapon_attachment_trigger_group,

		//WEAPON_ATTACHMENT_TARGET_TRACKING_TAG = 'wett'
		&weapon_attachment_target_tracking_group,

		//WEAPON_GLOBALS_TAG = 'wgbl'
		&weapon_globals_group,

		//USER_INTERFACE_GLOBALS_DEFINITION_TAG = 'wgtz'
		&user_interface_globals_definition_group,

		//USER_INTERFACE_SHARED_GLOBALS_DEFINITION_TAG = 'wigl'
		&user_interface_shared_globals_definition_group,

		//WIND_TAG = 'wind'
		&wind_group,

		//WATER_PHYSICS_DRAG_PROPERTIES_TAG = 'wpdp'
		&water_physics_drag_properties_group,

		//XANIMBLENDGRAPHNG_TAG = 'xbgt'
		&XAnimBlendGraphNG_group,

		//XMLTAG_TAG = 'xml*'
		&xmltag_group,

		//XOBJECTNODEGRAPH_TAG = 'xong'
		&XObjectNodeGraph_group,

		//GOBO_SETTING_TAG = 'GobS'
		&gobo_setting_group,

		//LIGHTING_SETTINGS_TAG = 'LigS'
		&lighting_settings_group,

		//RUNTIMEANIMSET_TAG = 'Rani'
		&RuntimeAnimSet_group,

		//STREAMINGZONESET_TAG = 'SDzs'
		&streamingzoneset_group,

		//ANIMNODEGRAPH_TAG = 'agct'
		&AnimNodeGraph_group,

		//ANIMSTATENODEGRAPH_TAG = 'asct'
		&AnimStateNodeGraph_group,

		//BLACKBOARDNODEGRAPH_TAG = 'bgct'
		&BlackboardNodeGraph_group,

		//BIPED_TAG = 'bipd'
		&biped_group,

		//CRATE_TAG = 'bloc'
		&crate_group,

		//BLEND1DNODEGRAPH_TAG = 'boct'
		&Blend1DNodeGraph_group,

		//BLENDRADIALNODEGRAPH_TAG = 'brct'
		&BlendRadialNodeGraph_group,

		//BLEND2DNODEGRAPH_TAG = 'btct'
		&Blend2DNodeGraph_group,

		//COMPOSITE_TAG = 'cpst'
		&composite_group,

		//CREATURE_TAG = 'crea'
		&creature_group,

		//DEVICE_TAG = 'devi'
		&device_group,

		//DECORATORSHADERGRAPH_TAG = 'dsct'
		&DecoratorShaderGraph_group,

		//DEVICE_DISPENSER_TAG = 'dspn'
		&device_dispenser_group,

		//ENCOUNTERBEHAVIORTREEDEFINITION_TAG = 'ebtc'
		&EncounterBehaviorTreeDefinition_group,

		//EFFECT_SCENERY_TAG = 'efsc'
		&effect_scenery_group,

		//FORGEMENUGRAPH_TAG = 'fmct'
		&ForgeMenuGraph_group,

		//FORGENODEGRAPH_TAG = 'fnct'
		&ForgeNodeGraph_group,

		//GIANT_TAG = 'gint'
		&giant_group,

		//ITEM_TAG = 'item'
		&item_group,

		//KIT_TAG = 'kit!'
		&kit_group,

		//LAYER_TAG = 'layr'
		&layer_group,

		//LEVEL_TAG = 'levl'
		&level_group,

		//LUANODEGRAPH_TAG = 'lgct'
		&LuaNodeGraph_group,

		//DEVICE_MACHINE_TAG = 'mach'
		&device_machine_group,

		//MATERIALSHADERGRAPH_TAG = 'msct'
		&MaterialShaderGraph_group,

		//RAW_GEO_TAG = 'rawg'
		&raw_geo_group,

		//DEVICE_TERMINAL_TAG = 'term'
		&device_terminal_group,

		//ULEVEL_TAG = 'ulvl'
		&ulevel_group,

		//WEAPON_TAG = 'weap'
		&weapon_group,

		//DEVICE_CONTROL_TAG = 'ctrl'
		&device_control_group,

		//EQUIPMENT_TAG = 'eqip'
		&equipment_group,
		nullptr
	};

} // namespace blofeld
