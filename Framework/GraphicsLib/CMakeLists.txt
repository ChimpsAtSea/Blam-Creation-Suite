add_library(GraphicsLib ${BCS_LIBRARY_TYPE}
	D3D12/d3d12_graphics.cpp
	D3D12/d3d12_graphics_buffer.cpp
	D3D12/d3d12_graphics_camera.cpp
	D3D12/d3d12_graphics_geometry.cpp
	D3D12/d3d12_graphics_render_instance.cpp
	D3D12/d3d12_graphics_render_pass.cpp
	D3D12/d3d12_graphics_render_target.cpp
	D3D12/d3d12_graphics_shader_binary.cpp
	D3D12/d3d12_graphics_shader_pipeline.cpp
	D3D12/d3d12_graphics_swap_chain.cpp
	D3D12/d3d12_graphics_texture.cpp
	D3D12/d3d12_graphics_vertex_layout.cpp
	D3D12/descriptor_heap_allocator_d3d12.cpp
	D3D12/descriptor_heap_d3d12.cpp
	D3D12/d3d12_imgui_context.cpp
	
	D3D11/graphics_d3d11.cpp
	D3D11/legacy_window.cpp
	
	Archetype/graphics.cpp
	Archetype/graphics_camera.cpp
	Archetype/graphics_render_instance.cpp
	Archetype/graphics_buffer.cpp
	Archetype/graphics_shader_binary.cpp
	Archetype/graphics_render_pass.cpp
	Archetype/graphics_render_target.cpp
	Archetype/graphics_texture.cpp
	Archetype/graphics_geometry.cpp
	Archetype/graphics_data_format.cpp
	Archetype/graphics_shader_pipeline.cpp
	Archetype/viewport.cpp
	Archetype/window.cpp
	Archetype/imgui_context.cpp
	Archetype/graphics_swap_chain.cpp
	Archetype/graphics_vertex_layout.cpp
	
	ImGui/begin_popup_modal_ex.cpp
	ImGui/imgui_memory_editor.cpp
	ImGui/imgui_text_editor.cpp
	ImGui/imgui_async_file_dialog.cpp
	
	Scenes/imgui_viewport_render_context.cpp
	Scenes/render_context.cpp
	
	Windows/window_windows.cpp
	
	ThirdParty/stb_image.cpp
    ThirdParty/stb_image_resize.cpp
    ThirdParty/tinyobjloader.cpp
	  
    Scenes/window_render_context.cpp
	
    Archetype/archetype-public-pch.h
    Archetype/graphics_camera.h
    Archetype/graphics_render_instance.h
    Archetype/viewport.h
	
    D3D11/d3d11-private-pch.h
    D3D11/graphics_d3d11.h
    D3D11/legacy_window.h
	
    D3D12/d3d12_gpu_data_structures.h
    D3D12/d3d12-private-pch.h
    D3D12/d3d12_graphics.h
    D3D12/d3d12_graphics_buffer.h
    D3D12/d3d12_graphics_camera.h
    D3D12/d3d12_graphics_geometry.h
    D3D12/d3d12_graphics_render_instance.h
    D3D12/d3d12_graphics_render_pass.h
    D3D12/d3d12_graphics_render_target.h
    D3D12/d3d12_graphics_shader_binary.h
    D3D12/d3d12_graphics_shader_pipeline.h
    D3D12/d3d12_graphics_swap_chain.h
    D3D12/d3d12_graphics_texture.h
    D3D12/d3d12_graphics_vertex_layout.h
    D3D12/descriptor_heap_allocator_d3d12.h
    D3D12/descriptor_heap_d3d12.h
    D3D12/d3d12_imgui_context.h
	
    dds.h
    graphicslib-private-pch.h
    graphicslib-public-pch.h
	
    Archetype/graphics.h
    Archetype/graphics_buffer.h
    Archetype/graphics_shader_binary.h
    Archetype/graphics_render_pass.h
    Archetype/graphics_render_target.h
    Archetype/graphics_texture.h
    Archetype/graphics_geometry.h
    Archetype/graphics_data_format.h
    Archetype/graphics_shader_pipeline.h
    Archetype/window.h
    Archetype/imgui_context.h
    Archetype/graphics_swap_chain.h
    Archetype/graphics_vertex_layout.h
	
    ImGui/begin_popup_modal_ex.h
    ImGui/imgui-public-pch.h
    ImGui/imgui_memory_editor.h
    ImGui/imgui_text_editor.h
    ImGui/imgui_async_file_dialog.h
	
    Scenes/imgui_viewport_render_context.h
    Scenes/render_context.h
	
    Windows/window_windows.h
	
    ThirdParty/stb_image.h
    ThirdParty/stb_image_resize.h
    ThirdParty/thirdparty-public-pch.h
    ThirdParty/tinyobjloader.h
	
    Windows/windows-private-pch.h
    Scenes/window_render_context.h
	
    HLSL/cpp_types.hlsli
    HLSL/descriptor_table.hlsli
    HLSL/generic_infinite_shader.hlsli
	
    HLSL/debug_shader.hlsl
    HLSL/default_shader.hlsl
    HLSL/generic_infinite_pixel_shader.hlsl
    HLSL/generic_infinite_vertex_shader.hlsl
    HLSL/vertex_layout_p.hlsl
    HLSL/vertex_layout_pc.hlsl
    HLSL/vertex_layout_ptcn.hlsl
	
	HLSL/LightmapDebug/lightmap_debug_vs.hlsl
	HLSL/LightmapDebug/lightmap_debug_ps.hlsl
	HLSL/LightmapDebug/lightmap_debug.hlsli)

bcs_set_common_properties(GraphicsLib)

set_source_files_properties(
	ThirdParty/stb_image.cpp
    ThirdParty/stb_image_resize.cpp
    ThirdParty/tinyobjloader.cpp
	PROPERTIES SKIP_PRECOMPILE_HEADERS ON)

set_source_files_properties(
	HLSL/debug_shader.hlsl
    HLSL/default_shader.hlsl
    HLSL/generic_infinite_pixel_shader.hlsl
	PROPERTIES VS_SHADER_TYPE Pixel)
set_source_files_properties(
    HLSL/generic_infinite_vertex_shader.hlsl
    HLSL/vertex_layout_p.hlsl
    HLSL/vertex_layout_pc.hlsl
    HLSL/vertex_layout_ptcn.hlsl
	PROPERTIES VS_SHADER_TYPE Vertex)

set_source_files_properties(
	HLSL/debug_shader.hlsl
    HLSL/default_shader.hlsl
    HLSL/generic_infinite_pixel_shader.hlsl
    HLSL/generic_infinite_vertex_shader.hlsl
    HLSL/vertex_layout_p.hlsl
    HLSL/vertex_layout_pc.hlsl
    HLSL/vertex_layout_ptcn.hlsl
	PROPERTIES VS_SHADER_MODEL 5.1)
	
#Lightmap Debug
set_source_files_properties(
	HLSL/LightmapDebug/lightmap_debug_vs.hlsl
	PROPERTIES VS_SHADER_TYPE Vertex)
set_source_files_properties(
	HLSL/LightmapDebug/lightmap_debug_ps.hlsl
	PROPERTIES VS_SHADER_TYPE Pixel)
set_source_files_properties(
	HLSL/LightmapDebug/lightmap_debug_vs.hlsl
	HLSL/LightmapDebug/lightmap_debug_ps.hlsl
	PROPERTIES VS_SHADER_MODEL 5.1)

target_link_libraries(GraphicsLib PRIVATE
	blamlib Platform TemplateLibrary xxhash imgui d3d11 d3d12 DirectX-Headers dxgi dxguid Shcore winpixeventruntime d3d12raytracingfallback directxshadercompiler)

target_precompile_headers(GraphicsLib PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:graphicslib-private-pch.h>")
	
set_target_properties(GraphicsLib PROPERTIES
	FOLDER "!Framework")
