from __future__ import print_function
import os
import sys
from shutil import copyfile

sys.path.append(os.path.realpath(os.path.dirname(__file__))) # Allow Local Imports

# -----
# Define Tag Definition Configurations
# -----
from library_bcs import Engine
from library_bcs import Platform
from library_bcs import Build
from library_bcs import EnginePlatformBuild

halo1_pc64_config = EnginePlatformBuild(Engine.engine_type_halo1, Platform.platform_type_pc_64bit, Build.build_guerilla)
stubbs_pc64_config = EnginePlatformBuild(Engine.engine_type_stubbs, Platform.platform_type_pc_64bit, Build.build_cache_release)
halo2_pc64_config = EnginePlatformBuild(Engine.engine_type_halo2, Platform.platform_type_pc_64bit, Build.build_guerilla)
halo3_pc64_config = EnginePlatformBuild(Engine.engine_type_halo3, Platform.platform_type_pc_64bit, Build.build_guerilla)
halo3odst_pc64_config = EnginePlatformBuild(Engine.engine_type_halo3odst, Platform.platform_type_pc_64bit, Build.build_guerilla)
eldorado_pc32_config = EnginePlatformBuild(Engine.engine_type_eldorado, Platform.platform_type_pc_32bit, Build.build_eldorado_1_106708_cert_ms23)
haloreach_xbox360_config = EnginePlatformBuild(Engine.engine_type_haloreach, Platform.platform_type_xbox_360, Build.build_tag_test)
haloreach_pc64_config = EnginePlatformBuild(Engine.engine_type_haloreach, Platform.platform_type_pc_64bit, Build.build_sapien)
halo4_xbox360_config = EnginePlatformBuild(Engine.engine_type_halo4, Platform.platform_type_xbox_360, Build.build_tag_test)
halo4_pc64_config = EnginePlatformBuild(Engine.engine_type_halo4, Platform.platform_type_pc_64bit, Build.build_sapien)
groundhog_pc64_config = EnginePlatformBuild(Engine.engine_type_groundhog, Platform.platform_type_pc_64bit, Build.build_sapien)
halo5_pc64_config = EnginePlatformBuild(Engine.engine_type_halo5, Platform.platform_type_pc_64bit, Build.build_cache_release)
haloinfinite_pc64_config = EnginePlatformBuild(Engine.engine_type_haloinfinite, Platform.platform_type_pc_64bit, Build.build_cache_release)

tag_configurations = [
    halo1_pc64_config,
    stubbs_pc64_config,
    halo2_pc64_config,
    halo3_pc64_config,
    halo3odst_pc64_config,
    eldorado_pc32_config,
    haloreach_xbox360_config,
    haloreach_pc64_config,
    halo4_xbox360_config,
    halo4_pc64_config,
    groundhog_pc64_config,
    halo5_pc64_config,
    haloinfinite_pc64_config ]

tag_configuration_triplets = []
for tag_configuration in tag_configurations:
    tag_configuration_triplets.append(f'{tag_configuration.engine.namespace}-{tag_configuration.platform.namespace}-{tag_configuration.build.namespace}')

tag_configuration_triplets_concat = ';'.join(tag_configuration_triplets)
