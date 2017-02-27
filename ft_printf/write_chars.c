/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 12:20:05 by tpan              #+#    #+#             */
/*   Updated: 2017/02/26 15:04:26 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_chars(t_conversion *conversion, va_list ap,
						t_format *format)
{
	char	*draft;

	if (conversion->flags.hash)
		return ;
	draft = ft_strnew(1);
	*draft = va_arg(ap ,int);
	apply_width(conversion, &draft);
	ft_putstr(draft);
	format->chars_written += ft_strlen(draft);
	ft_memdel((void **)&draft);
}
