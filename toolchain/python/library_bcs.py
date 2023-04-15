from library_util import pretty_print_dict

class Engine:
    type : str
    namespace : str
    pretty_name : str

    def __init__(self, type, namespace, pretty_name):
        self.type = type
        self.namespace = namespace
        self.pretty_name = pretty_name
        assert not namespace in Engine._by_namespace
        Engine._by_namespace[namespace] = self

    def __repr__(self):
        return pretty_print_dict(self.__dict__)
    
    @staticmethod
    def get_by_namespace(namespace : str):
        if namespace in Engine._by_namespace:
            return Engine._by_namespace[namespace]
        print(f'Failed to find namespace {namespace}')
        assert namespace in Engine._by_namespace
    
    @staticmethod
    def try_get_by_namespace(namespace : str):
        if namespace in Engine._by_namespace:
            return Engine._by_namespace[namespace]
        return Engine.engine_type_not_set
    
    _by_namespace = {}
    engine_type_not_set = None
    engine_type_halo1 = None
    engine_type_stubbs = None
    engine_type_halo2 = None
    engine_type_halo3 = None
    engine_type_halo3odst = None
    engine_type_eldorado = None
    engine_type_haloreach = None
    engine_type_halo4 = None
    engine_type_groundhog = None
    engine_type_halo5 = None
    engine_type_haloinfinite = None

class Platform:
    type : str
    namespace : str
    pretty_name : str

    def __init__(self, type, namespace, pretty_name):
        self.type = type
        self.namespace = namespace
        self.pretty_name = pretty_name
        assert not hasattr(Platform._by_namespace, namespace)
        Platform._by_namespace[namespace] = self

    def __repr__(self):
        return pretty_print_dict(self.__dict__)
    
    @staticmethod
    def get_by_namespace(namespace : str):
        if namespace in Platform._by_namespace:
            return Platform._by_namespace[namespace]
        print(f'Failed to find namespace {namespace}')
        assert namespace in Platform._by_namespace
    
    @staticmethod
    def try_get_by_namespace(namespace : str):
        if namespace in Platform._by_namespace:
            return Platform._by_namespace[namespace]
        return Platform.platform_type_not_set
    
    _by_namespace = {}
    platform_type_not_set = None
    platform_type_xbox = None
    platform_type_xbox_360 = None
    platform_type_xbox_one = None
    platform_type_pc_32bit = None
    platform_type_pc_64bit = None

class Build:
    type : str
    namespace : str
    pretty_name : str

    def __init__(self, type, namespace, pretty_name):
        self.type = type
        self.namespace = namespace
        self.pretty_name = pretty_name
        assert not hasattr(Build._by_namespace, namespace)
        Build._by_namespace[namespace] = self

    def __repr__(self):
        return pretty_print_dict(self.__dict__)
    
    @staticmethod
    def get_by_namespace(namespace : str):
        if namespace in Build._by_namespace:
            return Build._by_namespace[namespace]
        print(f'Failed to find namespace {namespace}')
        assert namespace in Build._by_namespace
    
    @staticmethod
    def try_get_by_namespace(namespace : str):
        if namespace in Build._by_namespace:
            return Build._by_namespace[namespace]
        return Build.build_not_set
  
    _by_namespace = {}
    build_not_set = None
    build_halo1_xbox = None
    build_halo1_beta_01_05_22_0268 = None
    build_halo1_demo = None
    build_halo1_pc_retail = None
    build_halo1_custom_edition = None
    build_halo1_anniversary_xbox360 = None
    build_halo1_anniversary_mcc = None
    build_stubbs = None
    build_mcc_1_824_0_0 = None
    build_mcc_1_887_0_0 = None
    build_mcc_1_1035_0_0 = None
    build_mcc_1_1186_0_0 = None
    build_mcc_1_1211_0_0 = None
    build_mcc_1_1246_0_0 = None
    build_mcc_1_1270_0_0 = None
    build_mcc_1_1305_0_0 = None
    build_mcc_1_1350_0_0 = None
    build_mcc_1_1367_0_0 = None
    build_mcc_1_1377_0_0 = None
    build_mcc_1_1384_0_0 = None
    build_mcc_1_1387_0_0 = None
    build_mcc_1_1389_0_0 = None
    build_mcc_1_1477_0_0 = None
    build_mcc_1_1499_0_0 = None
    build_mcc_1_1520_0_0 = None
    build_mcc_1_1570_0_0 = None
    build_mcc_1_1619_0_0 = None
    build_mcc_1_1629_0_0 = None
    build_mcc_1_1658_0_0 = None
    build_mcc_1_1698_0_0 = None
    build_mcc_1_1716_0_0 = None
    build_mcc_1_1767_0_0 = None
    build_mcc_1_1778_0_0 = None
    build_mcc_1_1792_0_0 = None
    build_mcc_1_1829_0_0 = None
    build_mcc_1_1864_0_0 = None
    build_mcc_1_1871_0_0 = None
    build_mcc_1_1896_0_0 = None
    build_mcc_1_1930_0_0 = None
    build_mcc_1_1955_0_0 = None
    build_mcc_1_2028_0_0 = None
    build_mcc_1_2094_0_0 = None
    build_eldorado_1_106708_cert_ms23 = None
    build_eldorado_1_155080_cert_ms23 = None
    build_eldorado_1_171227_cert_ms23 = None
    build_eldorado_1_177150_cert_ms23 = None
    build_eldorado_1_235640_cert_ms25 = None
    build_eldorado_1_301003_cert_MS26_new = None
    build_eldorado_1_327043_cert_ms26 = None
    build_eldorado_1_332089_Live = None
    build_eldorado_1_373869_Live = None
    build_eldorado_1_416138_Live = None
    build_eldorado_1_430653_Live = None
    build_eldorado_1_454665_Live = None
    build_eldorado_1_479394_Live = None
    build_eldorado_1_498295_Live = None
    build_eldorado_1_530945_Live = None
    build_eldorado_1_533032_Live = None
    build_eldorado_1_554482_Live = None
    build_eldorado_1_571698_Live = None
    build_eldorado_1_604673_Live = None
    build_eldorado_1_700255_cert_ms30_oct19 = None
    build_halo1_guerilla = None
    build_halo2_guerilla = None
    build_halo3_guerilla = None
    build_haloreach_tags = None
    build_halo5_forge_1_114_4592_2 = None
    build_halo5_forge_1_194_6192_2 = None
    build_infinite_FLT002INT_199229_21_07_20_0001 = None
    build_infinite_HIFLTA_202700_21_09_06_0001 = None
    build_infinite_HIREL_209048_21_12_09_1546 = None
    build_midnight_tag_test_untracked_november_13_2013 = None

    build_tag_debug = None
    build_tag_test = None
    build_tag_profile = None
    build_tag_release = None
    build_cache_debug = None
    build_cache_test = None
    build_cache_profile = None
    build_cache_release = None
    build_guerilla = None
    build_sapien = None
    build_tool = None

Platform.platform_type_not_set = Platform('platform_type_not_set', 'notset', 'Not Set')
Platform.platform_type_xbox = Platform('platform_type_xbox', 'xbox', 'Xbox')
Platform.platform_type_xbox_360 = Platform('platform_type_xbox_360', 'xbox360', 'Xbox 360')
Platform.platform_type_xbox_one = Platform('platform_type_xbox_one', 'xboxone', 'Xbox One')
Platform.platform_type_pc_32bit = Platform('platform_type_pc_32bit', 'pc32', 'PC (32bit)')
Platform.platform_type_pc_64bit = Platform('platform_type_pc_64bit', 'pc64', 'PC')

Engine.engine_type_not_set = Engine('engine_type_not_set', 'notset', 'Not Set')
Engine.engine_type_halo1 = Engine('engine_type_halo1', 'halo1', 'Halo 1')
Engine.engine_type_stubbs = Engine('engine_type_stubbs', 'stubbs', 'Stubbs the Zombie')
Engine.engine_type_halo2 = Engine('engine_type_halo2', 'halo2', 'Halo 2')
Engine.engine_type_halo3 = Engine('engine_type_halo3', 'halo3', 'Halo 3')
Engine.engine_type_halo3odst = Engine('engine_type_halo3odst', 'halo3odst', 'Halo 3: ODST')
Engine.engine_type_eldorado = Engine('engine_type_eldorado', 'eldorado', 'Eldorado')
Engine.engine_type_haloreach = Engine('engine_type_haloreach', 'haloreach', 'Halo Reach')
Engine.engine_type_halo4 = Engine('engine_type_halo4', 'halo4', 'Halo 4')
Engine.engine_type_groundhog = Engine('engine_type_groundhog', 'groundhog', 'Groundhog')
Engine.engine_type_halo5 = Engine('engine_type_halo5', 'halo5', 'Halo 5 Forge')
Engine.engine_type_haloinfinite = Engine('engine_type_haloinfinite', 'haloinfinite', 'Halo Infinite')

Build.build_not_set = Build('build_not_set', 'not_set', "Not set")
Build.build_halo1_xbox = Build('build_halo1_xbox', 'halo1_xbox', "Halo 1 Xbox")
Build.build_halo1_beta_01_05_22_0268 = Build('build_halo1_beta_01_05_22_0268', 'halo1_beta_01_05_22_0268', "Halo 1 PC Beta (01.05.23.0268)")
Build.build_halo1_demo = Build('build_halo1_demo', 'halo1_demo', "Halo 1 Demo")
Build.build_halo1_pc_retail = Build('build_halo1_pc_retail', 'halo1_pc_retail', "Halo 1 PC")
Build.build_halo1_custom_edition = Build('build_halo1_custom_edition', 'halo1_custom_edition', "Halo 1 Custom Edition")
Build.build_halo1_anniversary_xbox360 = Build('build_halo1_anniversary_xbox360', 'halo1_anniversary_xbox360', "Halo 1 Anniversary (Xbox 360)")
Build.build_halo1_anniversary_mcc = Build('build_halo1_anniversary_mcc', 'halo1_anniversary_mcc', "Halo 1 Anniversary (MCC)")
Build.build_stubbs = Build('build_stubbs', 'stubbs', "Stubbz Generic")
Build.build_mcc_1_824_0_0 = Build('build_mcc_1_824_0_0', 'mcc_1_824_0_0', "MCC 1.824.0.0")
Build.build_mcc_1_887_0_0 = Build('build_mcc_1_887_0_0', 'mcc_1_887_0_0', "MCC 1.887.0.0")
Build.build_mcc_1_1035_0_0 = Build('build_mcc_1_1035_0_0', 'mcc_1_1035_0_0', "MCC 1.1035.0.0")
Build.build_mcc_1_1186_0_0 = Build('build_mcc_1_1186_0_0', 'mcc_1_1186_0_0', "MCC 1.1186.0.0")
Build.build_mcc_1_1211_0_0 = Build('build_mcc_1_1211_0_0', 'mcc_1_1211_0_0', "MCC 1.1211.0.0")
Build.build_mcc_1_1246_0_0 = Build('build_mcc_1_1246_0_0', 'mcc_1_1246_0_0', "MCC 1.1246.0.0")
Build.build_mcc_1_1270_0_0 = Build('build_mcc_1_1270_0_0', 'mcc_1_1270_0_0', "MCC 1.1270.0.0")
Build.build_mcc_1_1305_0_0 = Build('build_mcc_1_1305_0_0', 'mcc_1_1305_0_0', "MCC 1.1305.0.0")
Build.build_mcc_1_1350_0_0 = Build('build_mcc_1_1350_0_0', 'mcc_1_1350_0_0', "MCC 1.1350.0.0")
Build.build_mcc_1_1367_0_0 = Build('build_mcc_1_1367_0_0', 'mcc_1_1367_0_0', "MCC 1.1367.0.0")
Build.build_mcc_1_1377_0_0 = Build('build_mcc_1_1377_0_0', 'mcc_1_1377_0_0', "MCC 1.1377.0.0")
Build.build_mcc_1_1384_0_0 = Build('build_mcc_1_1384_0_0', 'mcc_1_1384_0_0', "MCC 1.1384.0.0")
Build.build_mcc_1_1387_0_0 = Build('build_mcc_1_1387_0_0', 'mcc_1_1387_0_0', "MCC 1.1387.0.0")
Build.build_mcc_1_1389_0_0 = Build('build_mcc_1_1389_0_0', 'mcc_1_1389_0_0', "MCC 1.1389.0.0")
Build.build_mcc_1_1477_0_0 = Build('build_mcc_1_1477_0_0', 'mcc_1_1477_0_0', "MCC 1.1477.0.0")
Build.build_mcc_1_1499_0_0 = Build('build_mcc_1_1499_0_0', 'mcc_1_1499_0_0', "MCC 1.1499.0.0")
Build.build_mcc_1_1520_0_0 = Build('build_mcc_1_1520_0_0', 'mcc_1_1520_0_0', "MCC 1.1520.0.0")
Build.build_mcc_1_1570_0_0 = Build('build_mcc_1_1570_0_0', 'mcc_1_1570_0_0', "MCC 1.1570.0.0")
Build.build_mcc_1_1619_0_0 = Build('build_mcc_1_1619_0_0', 'mcc_1_1619_0_0', "MCC 1.1619.0.0")
Build.build_mcc_1_1629_0_0 = Build('build_mcc_1_1629_0_0', 'mcc_1_1629_0_0', "MCC 1.1629.0.0")
Build.build_mcc_1_1658_0_0 = Build('build_mcc_1_1658_0_0', 'mcc_1_1658_0_0', "MCC 1.1658.0.0")
Build.build_mcc_1_1698_0_0 = Build('build_mcc_1_1698_0_0', 'mcc_1_1698_0_0', "MCC 1.1698.0.0")
Build.build_mcc_1_1716_0_0 = Build('build_mcc_1_1716_0_0', 'mcc_1_1716_0_0', "MCC 1.1716.0.0")
Build.build_mcc_1_1767_0_0 = Build('build_mcc_1_1767_0_0', 'mcc_1_1767_0_0', "MCC 1.1767.0.0")
Build.build_mcc_1_1778_0_0 = Build('build_mcc_1_1778_0_0', 'mcc_1_1778_0_0', "MCC 1.1778.0.0")
Build.build_mcc_1_1792_0_0 = Build('build_mcc_1_1792_0_0', 'mcc_1_1792_0_0', "MCC 1.1792.0.0")
Build.build_mcc_1_1829_0_0 = Build('build_mcc_1_1829_0_0', 'mcc_1_1829_0_0', "MCC 1.1829.0.0")
Build.build_mcc_1_1864_0_0 = Build('build_mcc_1_1864_0_0', 'mcc_1_1864_0_0', "MCC 1.1864.0.0")
Build.build_mcc_1_1871_0_0 = Build('build_mcc_1_1871_0_0', 'mcc_1_1871_0_0', "MCC 1.1871.0.0")
Build.build_mcc_1_1896_0_0 = Build('build_mcc_1_1896_0_0', 'mcc_1_1896_0_0', "MCC 1.1896.0.0")
Build.build_mcc_1_1930_0_0 = Build('build_mcc_1_1930_0_0', 'mcc_1_1930_0_0', "MCC 1.1930.0.0")
Build.build_mcc_1_1955_0_0 = Build('build_mcc_1_1955_0_0', 'mcc_1_1955_0_0', "MCC 1.1955.0.0")
Build.build_mcc_1_2028_0_0 = Build('build_mcc_1_2028_0_0', 'mcc_1_2028_0_0', "MCC 1.2028.0.0")
Build.build_mcc_1_2094_0_0 = Build('build_mcc_1_2094_0_0', 'mcc_1_2094_0_0', "MCC 1.2094.0.0")
Build.build_eldorado_1_106708_cert_ms23 = Build('build_eldorado_1_106708_cert_ms23', 'eldorado_1_106708_cert_ms23', "Eldorado 1.106708 cert_ms23")
Build.build_eldorado_1_155080_cert_ms23 = Build('build_eldorado_1_155080_cert_ms23', 'eldorado_1_155080_cert_ms23', "Eldorado 1.155080 cert_ms23")
Build.build_eldorado_1_171227_cert_ms23 = Build('build_eldorado_1_171227_cert_ms23', 'eldorado_1_171227_cert_ms23', "Eldorado 1.171227 cert_ms23")
Build.build_eldorado_1_177150_cert_ms23 = Build('build_eldorado_1_177150_cert_ms23', 'eldorado_1_177150_cert_ms23', "Eldorado 1.177150 cert_ms23")
Build.build_eldorado_1_235640_cert_ms25 = Build('build_eldorado_1_235640_cert_ms25', 'eldorado_1_235640_cert_ms25', "Eldorado 1.235640 cert_ms25")
Build.build_eldorado_1_301003_cert_MS26_new = Build('build_eldorado_1_301003_cert_MS26_new', 'eldorado_1_301003_cert_MS26_new', "Eldorado 1.301003 cert_MS26_new")
Build.build_eldorado_1_327043_cert_ms26 = Build('build_eldorado_1_327043_cert_ms26', 'eldorado_1_327043_cert_ms26', "Eldorado 1.327043 cert_ms26")
Build.build_eldorado_1_332089_Live = Build('build_eldorado_1_332089_Live', 'eldorado_1_332089_Live', "Eldorado 1.332089 Live")
Build.build_eldorado_1_373869_Live = Build('build_eldorado_1_373869_Live', 'eldorado_1_373869_Live', "Eldorado 1.373869 Live")
Build.build_eldorado_1_416138_Live = Build('build_eldorado_1_416138_Live', 'eldorado_1_416138_Live', "Eldorado 1.416138 Live")
Build.build_eldorado_1_430653_Live = Build('build_eldorado_1_430653_Live', 'eldorado_1_430653_Live', "Eldorado 1.430653 Live")
Build.build_eldorado_1_454665_Live = Build('build_eldorado_1_454665_Live', 'eldorado_1_454665_Live', "Eldorado 1.454665 Live")
Build.build_eldorado_1_479394_Live = Build('build_eldorado_1_479394_Live', 'eldorado_1_479394_Live', "Eldorado 1.479394 Live")
Build.build_eldorado_1_498295_Live = Build('build_eldorado_1_498295_Live', 'eldorado_1_498295_Live', "Eldorado 1.498295 Live")
Build.build_eldorado_1_530945_Live = Build('build_eldorado_1_530945_Live', 'eldorado_1_530945_Live', "Eldorado 1.530945 Live")
Build.build_eldorado_1_533032_Live = Build('build_eldorado_1_533032_Live', 'eldorado_1_533032_Live', "Eldorado 1.533032 Live")
Build.build_eldorado_1_554482_Live = Build('build_eldorado_1_554482_Live', 'eldorado_1_554482_Live', "Eldorado 1.554482 Live")
Build.build_eldorado_1_571698_Live = Build('build_eldorado_1_571698_Live', 'eldorado_1_571698_Live', "Eldorado 1.571698 Live")
Build.build_eldorado_1_604673_Live = Build('build_eldorado_1_604673_Live', 'eldorado_1_604673_Live', "Eldorado 1.604673 Live")
Build.build_eldorado_1_700255_cert_ms30_oct19 = Build('build_eldorado_1_700255_cert_ms30_oct19', 'eldorado_1_700255_cert_ms30_oct19', "Eldorado 1.700255 cert_ms30_oct19")
Build.build_halo1_guerilla = Build('build_halo1_guerilla', 'halo1_guerilla', "Halo 1 Guerilla")
Build.build_halo2_guerilla = Build('build_halo2_guerilla', 'halo2_guerilla', "Halo 2 Guerilla")
Build.build_halo3_guerilla = Build('build_halo3_guerilla', 'halo3_guerilla', "Halo 3 Guerilla")
Build.build_haloreach_tags = Build('build_haloreach_tags', 'haloreach_tags', "Halo Reach Tags")
Build.build_halo5_forge_1_114_4592_2 = Build('build_halo5_forge_1_114_4592_2', 'halo5_forge_1_114_4592_2', "Halo 5 Forge 1.114.4592.2_x64__8wekyb3d8bbwe")
Build.build_halo5_forge_1_194_6192_2 = Build('build_halo5_forge_1_194_6192_2', 'halo5_forge_1_194_6192_2', "Halo 5 Forge 1.194.6192.2_x64__8wekyb3d8bbwe")
Build.build_infinite_FLT002INT_199229_21_07_20_0001 = Build('build_infinite_FLT002INT_199229_21_07_20_0001', 'infinite_FLT002INT_199229_21_07_20_0001', "Halo Infinite Flight 30/7/2021")
Build.build_infinite_HIFLTA_202700_21_09_06_0001 = Build('build_infinite_HIFLTA_202700_21_09_06_0001', 'infinite_HIFLTA_202700_21_09_06_0001', "Halo Infinite Flight 24/9/2021")
Build.build_infinite_HIREL_209048_21_12_09_1546 = Build('build_infinite_HIREL_209048_21_12_09_1546', 'infinite_HIREL_209048_21_12_09_1546', "Halo Infinite Release 21/12/2021")
Build.build_midnight_tag_test_untracked_november_13_2013 = Build('build_midnight_tag_test_untracked_november_13_2013', 'midnight_tag_test_untracked_november_13_2013', "Halo 4 midnight tag test xenon untracked Nov 13 2013 11:14:44")

Build.build_tag_debug = Build('build_tag_debug', 'tag_debug', "Tag Debug")
Build.build_tag_test = Build('build_tag_test', 'tag_test', "Tag Test")
Build.build_tag_profile = Build('build_tag_profile', 'tag_profile', "Tag Profile")
Build.build_tag_release = Build('build_tag_release', 'tag_release', "Tag Release")
Build.build_cache_debug = Build('build_cache_debug', 'cache_debug', "Cache Debug")
Build.build_cache_test = Build('build_cache_test', 'cache_test', "Cache Test")
Build.build_cache_profile = Build('build_cache_profile', 'cache_profile', "Cache Profile")
Build.build_cache_release = Build('build_cache_release', 'cache_release', "Cache Release")
Build.build_guerilla = Build('build_guerilla', 'guerilla', "Guerilla")
Build.build_sapien = Build('build_sapien', 'sapien', "Sapien")
Build.build_tool = Build('build_tool', 'tool', "Tool")

class EnginePlatformBuild:
    engine : Engine = None
    platform : Platform = None
    build : Build = None

    def __init__(self, engine : Engine = Engine.engine_type_not_set, platform : Platform = Platform.platform_type_not_set, build : Build = Build.build_not_set):
        self.engine = engine
        self.platform = platform
        self.build = build

    def __repr__(self):
        return pretty_print_dict(self.__dict__)
