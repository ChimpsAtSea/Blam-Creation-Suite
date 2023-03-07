#include "geometrylib-private-pch.h"

#define k_num_vertices_per_polygon 3

c_assimp_geometry_mesh::c_assimp_geometry_mesh(c_assimp_geometry_scene& _assimp_geometry_scene, aiMesh* _assimp_mesh) :
	c_geometry_mesh(),
	c_assimp_geometry_mesh_data(),
	DEBUG_ONLY(assimp_mesh(_assimp_mesh),)
	assimp_geometry_scene(_assimp_geometry_scene)
{
	BCS_VALIDATE_ARGUMENT_THROW(_assimp_mesh);

	num_faces = _assimp_mesh->mNumFaces;
	num_indices = num_faces * k_num_vertices_per_polygon;
	num_vertices = _assimp_mesh->mNumVertices;

	const char* assimp_mesh_name = _assimp_mesh->mName.C_Str();
	name = strdup(assimp_mesh_name);

	BCS_RESULT init_indices_result = init_indices(*_assimp_mesh);
	BCS_FAIL_THROW(init_indices_result);

	BCS_RESULT init_vertices_result = init_vertices(*_assimp_mesh);
	BCS_FAIL_THROW(init_vertices_result);

	BCS_RESULT init_texcoords_result = init_texcoords(*_assimp_mesh);
	BCS_FAIL_THROW(init_texcoords_result);

	BCS_RESULT init_colors_result = init_colors(*_assimp_mesh);
	BCS_FAIL_THROW(init_colors_result);
}

c_assimp_geometry_mesh::~c_assimp_geometry_mesh()
{
	deinit_geometry();
}

BCS_RESULT c_assimp_geometry_mesh::init_indices(aiMesh& assimp_mesh)
{
	mesh_indices_uint = new() unsigned int[num_indices];
	if (mesh_indices_uint == nullptr)
	{
		return BCS_E_OUT_OF_MEMORY;
	}

	unsigned int* mesh_indices_uint_write_position = mesh_indices_uint;
	for (unsigned int assimp_face_index = 0; assimp_face_index < assimp_mesh.mNumFaces; assimp_face_index++)
	{
		aiFace* assimp_face = assimp_mesh.mFaces + assimp_face_index;
		if (assimp_face->mNumIndices != k_num_vertices_per_polygon)
		{
			return BCS_E_FATAL;
		}
		for (unsigned int face_indices_index = 0; face_indices_index < assimp_face->mNumIndices; face_indices_index++)
		{
			*mesh_indices_uint_write_position++ = assimp_face->mIndices[face_indices_index];
		}
	}
	return BCS_S_OK;
}

BCS_RESULT c_assimp_geometry_mesh::init_short_indices()
{
	if (num_indices < USHRT_MAX)
	{
		mesh_indices_ushort = new() unsigned short[num_indices];
		if (mesh_indices_ushort == nullptr)
		{
			return BCS_E_OUT_OF_MEMORY;
		}

		for (unsigned int indice_index = 0; indice_index < num_indices; indice_index++)
		{
			unsigned int index = mesh_indices_uint[indice_index];
			if (index >= USHRT_MAX && index != UINT_MAX)
			{
				// the value of the index doesn't fit inside of an unsigned short
				delete[] mesh_indices_ushort;
				mesh_indices_ushort = nullptr;
				break;
			}
			mesh_indices_ushort[indice_index] = static_cast<unsigned short>(index);
		}
	}
	return BCS_S_OK;
}

BCS_RESULT c_assimp_geometry_mesh::init_texcoords(aiMesh& assimp_mesh)
{
	BCS_RESULT rs = BCS_S_OK;

	unsigned int internal_texture_coordinate_set_index = 0;
	for (unsigned int texture_coordinate_set_index = 0; texture_coordinate_set_index < k_num_assimp_texcoord_channels; texture_coordinate_set_index++)
	{
		if (assimp_mesh.HasTextureCoords(texture_coordinate_set_index))
		{
			float2* texture_coordinates_destination = new() float2[num_vertices];
			if (texture_coordinates_destination == nullptr)
			{
				return BCS_E_OUT_OF_MEMORY;
			}

			aiVector3D* texture_coordinates_source = assimp_mesh.mTextureCoords[texture_coordinate_set_index];

			for (unsigned int vertex_index = 0; vertex_index < num_vertices; vertex_index++)
			{
				aiVector3D* texture_coordinate_source = texture_coordinates_source + vertex_index;
				texture_coordinates_destination[vertex_index] =
				{
					texture_coordinate_source->x,
					texture_coordinate_source->y
				};
			}

			texture_coordinate_sets[internal_texture_coordinate_set_index] = texture_coordinates_destination;
			internal_texture_coordinate_set_index++;
		}
	}
	if (internal_texture_coordinate_set_index == 0) // ensure that channel 0 exists
	{
		float2* texture_coordinates_destination = new() float2[num_vertices];
		if (texture_coordinates_destination == nullptr)
		{
			return BCS_E_OUT_OF_MEMORY;
		}

		for (unsigned int vertex_index = 0; vertex_index < num_vertices; vertex_index++)
		{
			texture_coordinates_destination[vertex_index] = { 0.0f, 0.0f };
		}

		texture_coordinate_sets[internal_texture_coordinate_set_index] = texture_coordinates_destination;
	}

	return rs;
}

BCS_RESULT c_assimp_geometry_mesh::init_colors(aiMesh& assimp_mesh)
{
	BCS_RESULT rs = BCS_S_OK;

	unsigned int internal_color_set_index = 0;
	for (unsigned int color_set_index = 0; color_set_index < k_num_assimp_texcoord_channels; color_set_index++)
	{
		if (assimp_mesh.HasVertexColors(color_set_index))
		{
			float4* colors_destination = new() float4[color_set_index];
			if (colors_destination == nullptr)
			{
				return BCS_E_OUT_OF_MEMORY;
			}

			aiColor4D* colors_source = assimp_mesh.mColors[color_set_index];

			for (unsigned int vertex_index = 0; vertex_index < num_vertices; vertex_index++)
			{
				aiColor4D* color_source = colors_source + vertex_index;
				colors_destination[vertex_index] =
				{
					color_source->r,
					color_source->g,
					color_source->b,
					color_source->a
				};
			}

			color_sets[internal_color_set_index] = colors_destination;
			internal_color_set_index++;
		}
	}
	if (internal_color_set_index == 0) // ensure that channel 0 exists
	{
		float4* colors_destination = new() float4[num_vertices];
		if (colors_destination == nullptr)
		{
			return BCS_E_OUT_OF_MEMORY;
		}

		for (unsigned int vertex_index = 0; vertex_index < num_vertices; vertex_index++)
		{
			colors_destination[vertex_index] = { 1.0f, 1.0f, 1.0f, 1.0f };
		}

		color_sets[internal_color_set_index] = colors_destination;
	}

	return rs;
}

BCS_RESULT c_assimp_geometry_mesh::init_vertices(aiMesh& assimp_mesh)
{
	BCS_RESULT rs = BCS_S_OK;

	if (assimp_mesh.HasPositions())
	{
		positions = new() float3[num_vertices];
		if (positions == nullptr)
		{
			return BCS_E_OUT_OF_MEMORY;
		}

		aiVector3D* positions_source = assimp_mesh.mVertices;

		for (unsigned int vertex_index = 0; vertex_index < num_vertices; vertex_index++)
		{
			aiVector3D* position_source = positions_source + vertex_index;
			positions[vertex_index] =
			{
				position_source->x,
				position_source->y,
				position_source->z
			};
		}
	}
	else
	{
		positions = new() float3[num_vertices]{};
		if (positions == nullptr)
		{
			return BCS_E_OUT_OF_MEMORY;
		}
	}

	if (assimp_mesh.HasNormals())
	{
		normals = new() float3[num_vertices];
		if (normals == nullptr)
		{
			return BCS_E_OUT_OF_MEMORY;
		}

		aiVector3D* normals_source = assimp_mesh.mNormals;

		for (unsigned int vertex_index = 0; vertex_index < num_vertices; vertex_index++)
		{
			aiVector3D* normal_source = normals_source + vertex_index;
			normals[vertex_index] =
			{
				normal_source->x,
				normal_source->y,
				normal_source->z
			};
		}
	}
	else
	{
		normals = new() float3[num_vertices]{};
	}

	if (assimp_mesh.HasTangentsAndBitangents())
	{
		tangents = new() float3[num_vertices];
		if (tangents == nullptr)
		{
			return BCS_E_OUT_OF_MEMORY;
		}

		bitangents = new() float3[num_vertices];
		if (bitangents == nullptr)
		{
			return BCS_E_OUT_OF_MEMORY;
		}

		aiVector3D* tangents_source = assimp_mesh.mTangents;
		aiVector3D* bitangents_source = assimp_mesh.mBitangents;

		for (unsigned int vertex_index = 0; vertex_index < num_vertices; vertex_index++)
		{
			aiVector3D* tangent_source = tangents_source + vertex_index;
			tangents[vertex_index] =
			{
				tangent_source->x,
				tangent_source->y,
				tangent_source->z
			};

			aiVector3D* bitangent_source = bitangents_source + vertex_index;
			bitangents[vertex_index] =
			{
				bitangent_source->x,
				bitangent_source->y,
				bitangent_source->z
			};
		}
	}
	else
	{
		tangents = new() float3[num_vertices]{};
		if (tangents == nullptr)
		{
			return BCS_E_OUT_OF_MEMORY;
		}

		bitangents = new() float3[num_vertices]{};
		if (bitangents == nullptr)
		{
			return BCS_E_OUT_OF_MEMORY;
		}
	}

	return rs;
}

void c_assimp_geometry_mesh::degenerate_texcoord_hack()
{
	for (unsigned int texture_coordinate_set_index = 0; texture_coordinate_set_index < k_num_assimp_texcoord_channels; texture_coordinate_set_index++)
	{
		float2* texture_coordinates = texture_coordinate_sets[texture_coordinate_set_index];

		if (texture_coordinates != nullptr)
		{
			for (unsigned int face_index = 0; face_index < num_faces; face_index++)
			{
				unsigned int index_a = mesh_indices_uint[face_index * 3 + 0];
				unsigned int index_b = mesh_indices_uint[face_index * 3 + 1];
				unsigned int index_c = mesh_indices_uint[face_index * 3 + 2];

				float2& texcoord_a = texture_coordinates[index_a];
				float2& texcoord_b = texture_coordinates[index_b];
				float2& texcoord_c = texture_coordinates[index_c];

#define TRIANGLE_HACKS(a, b, threshold) \
			if ((__max(a, b) - __min(a, b)) < threshold) \
			{ \
				a -= __max(threshold, a * threshold); \
				b += __max(threshold, a * threshold); \
			}
				TRIANGLE_HACKS(texcoord_a.x, texcoord_b.x, FLT_EPSILON);
				TRIANGLE_HACKS(texcoord_b.x, texcoord_c.x, FLT_EPSILON);
				TRIANGLE_HACKS(texcoord_c.x, texcoord_a.x, FLT_EPSILON);
				TRIANGLE_HACKS(texcoord_a.y, texcoord_b.y, FLT_EPSILON);
				TRIANGLE_HACKS(texcoord_b.y, texcoord_c.y, FLT_EPSILON);
				TRIANGLE_HACKS(texcoord_c.y, texcoord_a.y, FLT_EPSILON);
			}
		}
	}
}

void c_assimp_geometry_mesh_data::deinit_geometry()
{
	untracked_free(name);
	delete[] positions;
	delete[] normals;
	delete[] tangents;
	delete[] bitangents;
	for (float2* texture_coordinates_buffer : texture_coordinate_sets)
	{
		delete[] texture_coordinates_buffer;
	}
	for (float4* colors_buffer : color_sets)
	{
		delete[] colors_buffer;
	}
	delete[] mesh_indices_ushort;
	delete[] mesh_indices_uint;
}


unsigned int c_assimp_geometry_mesh::get_vertex_count() const
{
	return num_vertices;
}

unsigned int c_assimp_geometry_mesh::get_index_count() const
{
	return num_indices;
}

unsigned int c_assimp_geometry_mesh::get_face_count() const
{
	return num_faces;
}

const char* c_assimp_geometry_mesh::get_name() const
{
	return name;
}

const float3* c_assimp_geometry_mesh::get_positions() const
{
	return positions;
}

const float3* c_assimp_geometry_mesh::get_normals() const
{
	return normals;
}

const float3* c_assimp_geometry_mesh::get_tangents() const
{
	return tangents;
}

const float3* c_assimp_geometry_mesh::get_bitangents() const
{
	return bitangents;
}

const float2* c_assimp_geometry_mesh::get_texture_coordinate_set(unsigned int index) const
{
	if (index < _countof(texture_coordinate_sets))
	{
		return texture_coordinate_sets[index];
	}
	return nullptr;
}

const float4* c_assimp_geometry_mesh::get_color_set(unsigned int index) const
{
	if (index < _countof(color_sets))
	{
		return color_sets[index];
	}
	return nullptr;
}

void* c_assimp_geometry_mesh::get_mesh_indices_raw() const
{
	if (mesh_indices_ushort != nullptr)
	{
		return mesh_indices_ushort;
	}
	return mesh_indices_uint;
}

unsigned int* c_assimp_geometry_mesh::get_mesh_indices_uint() const
{
	return mesh_indices_uint;
}

e_geometry_mesh_index_format c_assimp_geometry_mesh::get_mesh_index_format() const
{
	if (mesh_indices_ushort != nullptr)
	{
		return _geometry_mesh_index_format_ushort;
	}
	return _geometry_mesh_index_format_uint;
}

bool c_assimp_geometry_mesh::is_read_only() const
{
	return false;
}

BCS_RESULT c_assimp_geometry_mesh::resize_vertex_count(unsigned int new_num_vertices)
{
	if (new_num_vertices <= num_vertices)
	{
		num_vertices = new_num_vertices;
	}
	else
	{
		c_assimp_geometry_mesh_data new_geometry_mesh_data = {};

		new_geometry_mesh_data.num_faces = num_faces;
		new_geometry_mesh_data.num_indices = num_indices;
		new_geometry_mesh_data.mesh_indices_uint = mesh_indices_uint;
		new_geometry_mesh_data.mesh_indices_ushort = mesh_indices_ushort;

		new_geometry_mesh_data.name = strdup(name);

		new_geometry_mesh_data.positions = new() float3[new_geometry_mesh_data.num_vertices]{};
		if (new_geometry_mesh_data.positions == nullptr)
		{
			new_geometry_mesh_data.deinit_geometry();
			return BCS_E_OUT_OF_MEMORY;
		}

		new_geometry_mesh_data.normals = new() float3[new_geometry_mesh_data.num_vertices]{};
		if (new_geometry_mesh_data.normals == nullptr)
		{
			new_geometry_mesh_data.deinit_geometry();
			return BCS_E_OUT_OF_MEMORY;
		}

		new_geometry_mesh_data.tangents = new() float3[new_geometry_mesh_data.num_vertices]{};
		if (new_geometry_mesh_data.tangents == nullptr)
		{
			new_geometry_mesh_data.deinit_geometry();
			return BCS_E_OUT_OF_MEMORY;
		}

		new_geometry_mesh_data.bitangents = new() float3[new_geometry_mesh_data.num_vertices]{};
		if (new_geometry_mesh_data.bitangents == nullptr)
		{
			new_geometry_mesh_data.deinit_geometry();
			return BCS_E_OUT_OF_MEMORY;
		}

		memcpy(new_geometry_mesh_data.positions, positions, sizeof(*positions) * new_geometry_mesh_data.num_vertices);
		memcpy(new_geometry_mesh_data.normals, normals, sizeof(*normals) * new_geometry_mesh_data.num_vertices);
		memcpy(new_geometry_mesh_data.tangents, tangents, sizeof(*tangents) * new_geometry_mesh_data.num_vertices);
		memcpy(new_geometry_mesh_data.bitangents, bitangents, sizeof(*bitangents) * new_geometry_mesh_data.num_vertices);

		for (unsigned int color_set_index = 0; color_set_index < k_num_assimp_texcoord_channels; color_set_index++)
		{
			float4* old_colors = color_sets[color_set_index];

			if (old_colors == nullptr)
			{
				new_geometry_mesh_data.color_sets[color_set_index] = nullptr;
			}
			else
			{
				float4* new_colors = new() float4[new_geometry_mesh_data.num_vertices];
				if (new_colors == nullptr)
				{
					new_geometry_mesh_data.deinit_geometry();
					return BCS_E_OUT_OF_MEMORY;
				}
				for (unsigned int vertex_index = 0; vertex_index < new_geometry_mesh_data.num_vertices; vertex_index++)
				{
					new_colors[vertex_index] = { 1.0f, 1.0f, 1.0f, 1.0f };
				}
				memcpy(new_colors, old_colors, sizeof(*new_colors) * new_geometry_mesh_data.num_vertices);
				new_geometry_mesh_data.color_sets[color_set_index] = new_colors;
			}
		}

		for (unsigned int texture_coordinate_set_index = 0; texture_coordinate_set_index < k_num_assimp_texcoord_channels; texture_coordinate_set_index++)
		{
			float2* old_texture_coordinates = texture_coordinate_sets[texture_coordinate_set_index];
			if (old_texture_coordinates == nullptr)
			{
				new_geometry_mesh_data.texture_coordinate_sets[texture_coordinate_set_index] = nullptr;
			}
			else
			{
				float2* new_texture_coordinates = new() float2[new_geometry_mesh_data.num_vertices]{};
				if (new_texture_coordinates == nullptr)
				{
					new_geometry_mesh_data.deinit_geometry();
					return BCS_E_OUT_OF_MEMORY;
				}
				memcpy(new_texture_coordinates, old_texture_coordinates, sizeof(*new_texture_coordinates) * new_geometry_mesh_data.num_vertices);
				new_geometry_mesh_data.texture_coordinate_sets[texture_coordinate_set_index] = new_texture_coordinates;
			}
		}

		deinit_geometry();

		c_assimp_geometry_mesh_data& geometry_mesh_data = *this;
		geometry_mesh_data = new_geometry_mesh_data;
	}

	return BCS_S_OK;
}

BCS_RESULT c_assimp_geometry_mesh::resize_face_and_index_count(unsigned int new_num_faces, unsigned int new_num_indices)
{
	if (new_num_faces <= num_faces && new_num_indices <= num_indices)
	{
		num_faces = new_num_faces;
		num_indices = new_num_indices;
	}
	else
	{
		// reset existing short indices
		if (mesh_indices_ushort != nullptr)
		{
			delete[] mesh_indices_ushort;
			mesh_indices_ushort = nullptr;
		}

		unsigned int* new_mesh_indices_uint = new() unsigned int[new_num_indices];
		if (new_mesh_indices_uint == nullptr)
		{
			return BCS_E_OUT_OF_MEMORY;
		}

		memset(new_mesh_indices_uint, -1, sizeof(*new_mesh_indices_uint) * new_num_indices); // make sure new indices are max value
		memcpy(new_mesh_indices_uint, mesh_indices_uint, sizeof(*mesh_indices_uint) * new_num_indices);

		delete[] mesh_indices_uint;
		mesh_indices_uint = new_mesh_indices_uint;
		num_faces = new_num_faces;
		num_indices = new_num_indices;
	}

	return BCS_S_OK;
}

BCS_RESULT c_assimp_geometry_mesh::write_indices(const unsigned int* new_indices, unsigned int num_indices, unsigned int offset)
{
	unsigned int new_num_indices = num_indices + offset;

	// #TODO: is this safe?
	unsigned int new_num_faces = new_num_indices / 3;

	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = resize_face_and_index_count(__max(new_num_faces, num_faces), __max(new_num_indices, num_vertices))))
	{
		return rs;
	}

	for (unsigned int indice_index = 0; indice_index < new_num_indices; indice_index++)
	{
		mesh_indices_uint[indice_index + offset] = new_indices[indice_index];
	}

	// reset existing short indices
	if (mesh_indices_ushort != nullptr)
	{
		delete[] mesh_indices_ushort;
		mesh_indices_ushort = nullptr;
	}

	init_short_indices();

	return rs;
}

BCS_RESULT c_assimp_geometry_mesh::write_positions(const float3* new_positions, unsigned int num_write_vertices, unsigned int offset)
{
	unsigned int new_num_vertices = num_write_vertices + offset;

	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = resize_vertex_count(__max(new_num_vertices, num_vertices))))
	{
		return rs;
	}

	for (unsigned int vertex_index = 0; vertex_index < new_num_vertices; vertex_index++)
	{
		positions[vertex_index + offset] = new_positions[vertex_index];
	}
	
	return rs;
}

BCS_RESULT c_assimp_geometry_mesh::write_normals(const float3* new_normals, unsigned int num_write_vertices, unsigned int offset)
{
	unsigned int new_num_vertices = num_write_vertices + offset;

	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = resize_vertex_count(__max(new_num_vertices, num_vertices))))
	{
		return rs;
	}

	for (unsigned int vertex_index = 0; vertex_index < new_num_vertices; vertex_index++)
	{
		normals[vertex_index + offset] = new_normals[vertex_index];
	}

	init_short_indices();

	return rs;
}

BCS_RESULT c_assimp_geometry_mesh::write_tangents(const float3* new_tangents, unsigned int num_write_vertices, unsigned int offset)
{
	unsigned int new_num_vertices = num_write_vertices + offset;

	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = resize_vertex_count(__max(new_num_vertices, num_vertices))))
	{
		return rs;
	}

	for (unsigned int vertex_index = 0; vertex_index < new_num_vertices; vertex_index++)
	{
		tangents[vertex_index + offset] = new_tangents[vertex_index];
	}

	return rs;
}

BCS_RESULT c_assimp_geometry_mesh::write_bitangents(const float3* new_bitangents, unsigned int num_write_vertices, unsigned int offset)
{
	unsigned int new_num_vertices = num_write_vertices + offset;

	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = resize_vertex_count(__max(new_num_vertices, num_vertices))))
	{
		return rs;
	}

	for (unsigned int vertex_index = 0; vertex_index < new_num_vertices; vertex_index++)
	{
		bitangents[vertex_index + offset] = new_bitangents[vertex_index];
	}

	return rs;
}

BCS_RESULT c_assimp_geometry_mesh::write_texture_coordinate_set(unsigned int index, const float2* new_texture_coordinates, unsigned int num_write_vertices, unsigned int offset)
{
	unsigned int new_num_vertices = num_write_vertices + offset;

	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = resize_vertex_count(__max(new_num_vertices, num_vertices))))
	{
		return rs;
	}

	float2* texture_coordinate_set = texture_coordinate_sets[index];

	if (texture_coordinate_set == nullptr)
	{
		texture_coordinate_set = texture_coordinate_sets[index] = new() float2[num_vertices]{};
		if (texture_coordinate_set == nullptr)
		{
			return BCS_E_OUT_OF_MEMORY;
		}
	}

	for (unsigned int vertex_index = 0; vertex_index < new_num_vertices; vertex_index++)
	{
		texture_coordinate_set[vertex_index + offset] = new_texture_coordinates[vertex_index];
	}

	return rs;
}

BCS_RESULT c_assimp_geometry_mesh::write_color_set(unsigned int index, const float4* new_colors, unsigned int num_write_vertices, unsigned int offset)
{
	unsigned int new_num_vertices = num_write_vertices + offset;

	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = resize_vertex_count(__max(new_num_vertices, num_vertices))))
	{
		return rs;
	}

	float4* color_set = color_sets[index];

	if (color_set == nullptr)
	{
		color_set = color_sets[index] = new() float4[num_vertices];
		if (color_set == nullptr)
		{
			return BCS_E_OUT_OF_MEMORY;
		}
		for (unsigned int vertex_index = 0; vertex_index < new_num_vertices; vertex_index++)
		{
			color_set[vertex_index] = { 1.0f, 1.0f, 1.0f, 1.0f };
		}
	}

	for (unsigned int vertex_index = 0; vertex_index < new_num_vertices; vertex_index++)
	{
		color_set[vertex_index + offset] = new_colors[vertex_index];
	}

	return rs;
}

