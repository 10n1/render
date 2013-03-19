/*
 * render.h
 */

typedef struct _mesh
{
	void* vertex_data;
	void* index_data;

	unsigned int vertex_count;
	unsigned int index_count;

	unsigned int mesh_id;
} mesh;

typedef struct _texture
{
	void* texture_data;

	unsigned int texture_id;
} texture;

typedef struct _transform
{
	float4x4 m;
} transform;

typedef struct _render_target
{
	unsigned int width;
	unsigned int height;
	unsigned int render_target_id;
} render_target;

/* C */
#ifdef __cplusplus
extern "C" {
#endif

void render_init( void );
void render_draw_mesh( render_target* target, mesh* mesh, transform m );

render_target* render_create_target( unsigned int width, unsigned int height );
mesh* render_create_mesh( void* mesh_data );
texture* render_create_texture( void* texture_data );
shader* render_create_vertex_shader( const char* shader_source );
shader* render_create_pixel_shader( const char* shader_source );

#ifdef __cplusplus
}
#endif


/* C++ */

class render {
public:
	render( void );
	~render( void );

	void draw_mesh( render_target* target, mesh* mesh, transform m );

	render_target* create_target( unsigned int width, unsigned int height );
	mesh* create_mesh( void* mesh_data );
	texture* create_texture( void* texture_data );
	shader* create_vertex_shader( const char* shader_source );
	shader* create_pixel_shader( const char* shader_source );
};
