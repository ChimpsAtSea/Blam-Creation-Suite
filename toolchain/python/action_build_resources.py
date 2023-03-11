import os
import sys
sys.path.append(os.path.realpath(os.path.dirname(__file__))) # Allow Local Imports
import library_util as util
from task_manager import BuildTaskManager
from task_build_copy import CopyBuildTask
util.async_start()

directxshadercompiler_directory = os.path.join(util.bcs_third_party_dir, 'directxshadercompiler/directxshadercompiler')
dxc = os.path.join(directxshadercompiler_directory, 'bin/dxc')

#print('target_src_dir', util.target_src_dir)
#print('target_gen_dir', util.target_gen_dir)
#print('target_out_dir', util.target_out_dir)
#print('root_out_dir', util.root_out_dir)
#print('root_gen_dir', util.root_gen_dir)
#print('root_build_dir', util.root_build_dir)

inputs = util.command_line['inputs']
sources = util.command_line['sources']
outputs = util.command_line['outputs']
output_subdirectory = util.command_line['output-subdirectory']

#print('inputs', inputs)
#print('sources', sources)
#print('outputs', outputs)
#print('output_subdirectory', output_subdirectory)

copy_tasks = []
for index, source in enumerate(sources):
    source : str
    abs_source = source
    if os.path.isabs(source):
        abs_source = os.path.relpath(source, util.target_src_dir)
    else:
        source = os.path.join(util.target_src_dir, source)

    filename = os.path.basename(abs_source)
    output = os.path.join(util.root_build_dir, output_subdirectory, filename)

    source_root_relative_path = os.path.relpath(source, util.bcs_root_dir)
    output_root_relative_path = os.path.relpath(output, util.bcs_root_dir)

    #print("Copying", source_root_relative_path, output_root_relative_path)
    copy_tasks.append(CopyBuildTask(source, output))

BuildTaskManager.run_until_complete()
util.async_end()
