import os
import sys

sys.path.append(os.path.realpath(os.path.dirname(__file__))) # Allow Local Imports

import project_setup
import sln
import gn
import util

util.async_start()

target_os = util.command_line["target_os"]
target_config = util.command_line["target_config"]
target_link_config = util.command_line["target_link_config"]
target_cpu = util.command_line["target_cpu"]

gn.generate_build_configuration_files(target_os, target_config, target_link_config, target_cpu, True)
global_targets = project_setup.parse_global_targets_list('//solution')

print("Setting up Visual Studio Projects")
solution = sln.Solution('Blam Creation Suite', 'solution/blamcreationsuite.sln')
project_setup.setup_solution_project_structure(solution, global_targets)

for project in solution.projects:
    sln.write_project(solution, project)
sln.write_solution("solution/", solution)

util.async_end()
