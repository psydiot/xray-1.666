
#include "stdafx.h"
struct SCREEN;
#define MAXIMUM_D3D_VERTICES_IN_VERTEX_BUFFER 378

#define MAXIMUM_D3D_INDICES_IN_VERTEX_BUFFER 2048

#define MAXIMUM_TRIANGLE_BUFFERS 32

#define MAXIMUM_LINE_BUFFERS 2

#define MAX_ALPHA_VERTEX_BUFFERS 16
struct VERTEX_BUFFER_TEXTURE_DATA
{

	struct SCREEN
		*texture;

	union
	{

		struct
		{

			unsigned char
				mipmap_filter,
				linear_filter,
				clamp_u,
				clamp_v;
		};

		unsigned int
			texture_settings;
	};
};

typedef struct VERTEX_BUFFER_TEXTURE_DATA vertex_buffer_texture_data;
struct VERTEX_BUFFER_HEADER
{

	struct VERTEX_BUFFER_HEADER
		*pred,
		*succ;

	vertex_buffer_texture_data
		texture;

	int
		vertices_used,
		indices_index;

	D3DVERTEXELEMENT9
		*vertices;

	LPDIRECT3DVERTEXBUFFER9
		buffer;

	WORD
		indices[MAXIMUM_D3D_INDICES_IN_VERTEX_BUFFER];
};

typedef struct VERTEX_BUFFER_HEADER vertex_buffer_header;
struct DIRECT_3D_DATA
{
	LPDIRECT3D9
		d3d;

	LPDIRECT3DDEVICE9
		device;

	int
		use_emulation,
		use_rgb,
		recreate_d3d;
};

struct DIRECT_3D_VECTORS
{
	vertex_buffer_header
		triangle_buffers[MAXIMUM_TRIANGLE_BUFFERS],
		line_buffers[MAXIMUM_LINE_BUFFERS],
		*triangle_buffer,
		*free_triangle_buffers,
		*inuse_triangle_buffers,
		*line_buffer,
		*free_line_buffer,
		*inuse_line_buffer;

	LPDIRECT3DVERTEXBUFFER9
		//		primary_triangle_vertex_buffer,
		//		secondary_triangle_vertex_buffer,
		//		current_triangle_vertex_buffer,
		//		primary_line_vertex_buffer,
		//		secondary_line_vertex_buffer,
		//		current_line_vertex_buffer,
		point_vertex_buffer,
		hardware_untransformed_buffer,
		alpha_vertex_buffer[MAX_ALPHA_VERTEX_BUFFERS];
};
struct DIRECT_3D_DATA
d3d_data;
 struct DIRECT_3D_VECTORS
d3d;
