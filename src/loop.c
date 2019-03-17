/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:27:53 by jleblond          #+#    #+#             */
/*   Updated: 2019/03/15 16:30:47 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		loop(t_context *ct)
{
	Uint8		*state;

	ct->cam.angle = 10;
	while (TRUE)
	{
		SDL_PollEvent(ct->ev);
		state = (Uint8*)SDL_GetKeyboardState(NULL);
		state[SDL_SCANCODE_ESCAPE] ? exit(0) : 0;
		state[SDL_SCANCODE_A] ? ct->cam.angle += 0.05 : 0;
		state[SDL_SCANCODE_S] ? ct->cam.angle -= 0.05 : 0;

//----------------jie
		draw_2d(ct);
		//draw_background(ct);

		//jie-------
//----------------laeti

		//----------------laeti-------
		SDL_RenderPresent(ct->rend);
	}
}



