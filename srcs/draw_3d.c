
#include "wolf3d.h"

void	draw_wall(t_context *ct)
{
	float	angle;
	int		x_pixel;

	angle = ct->cam.angle;
	x_pixel = XWIN / 2;
	draw_line_wall(ct, angle, x_pixel);
	while (x_pixel >= 0)
	{
		x_pixel--;
		angle += 30.0 / (float)(XWIN / 2);
		draw_line_wall(ct, angle, x_pixel);

	}
	angle = ct->cam.angle;
	x_pixel = XWIN / 2;
	while (x_pixel <= XWIN)
	{
		x_pixel++;
		angle -= 30.0 / (float)(XWIN / 2);
		draw_line_wall(ct, angle, x_pixel);
	}
}

void	draw_line_wall(t_context *ct, float angle, int	x_pixel)
{
	float		distance;
	int			wall_height;
	SDL_Point 	top;
	SDL_Point 	down;


	distance = dda_return_distance(ct, angle);
	if (distance < 0) // distance will be negative if no wall
		return ;
	wall_height = convert_mapdis_to_screendis(distance, ct);
	top.x = x_pixel;
	top.y = (YWIN - wall_height) / 2;
	down.x = x_pixel;
	down.y = (YWIN + wall_height) / 2;
	SDL_SetRenderDrawColor(ct->rend, 0, 51 , 102, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(ct->rend, top.x, top.y, down.x, down.y);
}

int		convert_mapdis_to_screendis(float distance, t_context *ct)
{
	float	dis_max;
	float	dis_min;
	int		wall_height;

	dis_max = sqrt(pow(ct->mpp.x, 2) + pow(ct->mpp.y, 2));
	dis_min = 0.1;
	if (distance < dis_min)
		distance = dis_min;


	wall_height = (dis_max - distance) * 10 / distance;
	return (wall_height);
}