
D3D12_INPUT_ELEMENT_DESC p_vertex_layout_descriptions[] =
{
	{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, static_cast<UINT>(offsetof(s_geometry_vertex_position, s_geometry_vertex_position::position)), D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
};

D3D12_INPUT_ELEMENT_DESC pc_vertex_layout_descriptions[] =
{
	{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, static_cast<UINT>(offsetof(s_geometry_vertex_position, s_geometry_vertex_position::position)), D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
	{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 1,  static_cast<UINT>(offsetof(s_geometry_vertex_extra, s_geometry_vertex_extra::color)), D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
};

D3D12_INPUT_ELEMENT_DESC ptcn_vertex_layout_descriptions[] =
{
	{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, static_cast<UINT>(offsetof(s_geometry_vertex_position, s_geometry_vertex_position::position)), D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
	{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 1,  static_cast<UINT>(offsetof(s_geometry_vertex_extra, s_geometry_vertex_extra::texcoord)), D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
	{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 1,  static_cast<UINT>(offsetof(s_geometry_vertex_extra, s_geometry_vertex_extra::color)), D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
	{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 1,  static_cast<UINT>(offsetof(s_geometry_vertex_extra, s_geometry_vertex_extra::normal)), D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 }
};

s_graphics_vertex_layout_description vertex_layout_descriptions[] =
{
	{p_vertex_layout_descriptions, _countof(p_vertex_layout_descriptions)},
	{pc_vertex_layout_descriptions, _countof(pc_vertex_layout_descriptions)},
	{ptcn_vertex_layout_descriptions, _countof(ptcn_vertex_layout_descriptions)},
};
static_assert(_countof(vertex_layout_descriptions) == k_number_of_vertex_layout_types);
