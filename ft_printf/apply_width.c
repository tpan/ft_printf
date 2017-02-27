/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:07:51 by tpan              #+#    #+#             */
/*   Updated: 2017/02/27 10:42:49 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			apply_width_str(t_conversion *conversion, char **draft)
{
	char	*temp;

	if (conversion->width > ft_strlen(*draft))
	{
		temp = *draft;
		*draft = ft_strnew(conversion->width);
		if (conversion->flags.left_justify)
		{
			ft_strcpy(*draft, temp);
			ft_memset(&(*draft)[ft_strlen(temp)], ' ',
										conversion->width - ft_strlen(temp));
		}
		else
		{
			ft_memset(*draft, ' ', conversion->width - ft_strlen(temp));
			ft_strcpy(&(*draft)[conversion->width - ft_strlen(temp)], temp);
		}
		ft_memdel((void **)&temp);
	}
	return ;
}

static void			apply_width_int(t_conversion *conversion, char **draft)
{
	char	*temp;

	if (ft_strlen(*draft) < conversion->width)
	{
		temp = *draft;
		*draft = ft_strnew(conversion->width);
		if (conversion->flags.left_justify)
		{
			ft_strcpy(*draft, temp);
			ft_memset(&(*draft)[ft_strlen(*draft)], ' ',
										conversion->width - ft_strlen(*draft));
		}
		else
		{
			ft_memset(*draft, (conversion->flags.pad_zeros ? '0' : ' '),
										conversion->width - ft_strlen(temp));
			ft_strcpy(&(*draft)[conversion->width - ft_strlen(temp)], temp);
		}
		ft_memdel((void **)&temp);
	}
}

void				apply_width(t_conversion *conversion, char **draft)
{
	if (conversion->specifier == STRING)
		apply_width_str(conversion, draft);
	else
		apply_width_int(conversion, draft);
	return ;
}