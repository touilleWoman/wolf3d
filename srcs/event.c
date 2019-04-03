/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 09:09:53 by jleblond          #+#    #+#             */
/*   Updated: 2019/04/03 09:09:58 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	key_events_2d(t_context *ct, Uint8 *state, unsigned int delta_time)
{
	float	d;

	d =  2.0 * delta_time / 1000;
	if ((ct->cam.posi.y - d > 0)
		&& ct->mpp.map[(int)(ct->cam.posi.y - d)][(int)ct->cam.posi.x] != 1)
		state[SDL_SCANCODE_I] ? ct->cam.posi.y -= d : 0;
	if ((ct->cam.posi.y + d < ct->mpp.y)
		&& ct->mpp.map[(int)(ct->cam.posi.y + d)][(int)ct->cam.posi.x] != 1)
		state[SDL_SCANCODE_K] ? ct->cam.posi.y += d : 0;
	if ((ct->cam.posi.x - d > 0)
		&& ct->mpp.map[(int)ct->cam.posi.y][(int)(ct->cam.posi.x - d)] != 1)
		state[SDL_SCANCODE_J] ? ct->cam.posi.x -= d : 0;
	if ((ct->cam.posi.x + d < ct->mpp.x)
		&& ct->mpp.map[(int)ct->cam.posi.y][(int)(ct->cam.posi.x + d)] != 1)
		state[SDL_SCANCODE_L] ? ct->cam.posi.x += d : 0;
}

static void	key_events_3d(t_context *ct, Uint8 *state, unsigned delta_time)
{
	float	d;
	float	dx;
	float	dy;

	d = 0.005 * (float)delta_time / 2.0;
	dy = d * sin(convert_deg_to_rad(ct->cam.angle));
	dx = d * cos(convert_deg_to_rad(ct->cam.angle));
	if ((ct->cam.posi.y - dy > 0) && (ct->cam.posi.y - dy < ct->mpp.y)
		&& (ct->cam.posi.x + dx < ct->mpp.x) && (ct->cam.posi.x + dx > 0)
		&& ct->mpp.map[(int)(ct->cam.posi.y - dy)][(int)(ct->cam.posi.x + dx)] != 1)
	{
		if (state[SDL_SCANCODE_UP])
		{
			ct->cam.posi.y -= dy ;
			ct->cam.posi.x += dx ;
		}
	}
	if ((ct->cam.posi.y + dy < ct->mpp.y) && (ct->cam.posi.y + dy > 0)
		&& (ct->cam.posi.x - dx > 0) && (ct->cam.posi.x - dx < ct->mpp.x)
		&& ct->mpp.map[(int)(ct->cam.posi.y + dy)][(int)(ct->cam.posi.x - dx)] != 1)
	{
		if (state[SDL_SCANCODE_DOWN])
		{
			ct->cam.posi.y += dy;
			ct->cam.posi.x -= dx;
		}
	}
}

void	key_events(t_context *ct, Uint8 *state, unsigned int delta_time)
{
	state[SDL_SCANCODE_ESCAPE] ? quit("Thank you for playing", ct) : 0;
	state[SDL_SCANCODE_LEFT] ? ct->cam.angle += 50.0 * delta_time/1000 : 0;
	state[SDL_SCANCODE_RIGHT] ? ct->cam.angle -= 50.0 * delta_time/1000 : 0;
	key_events_2d(ct, state, delta_time);
	key_events_3d(ct, state, delta_time);

}
