/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:19:10 by rlevine           #+#    #+#             */
/*   Updated: 2017/10/13 16:06:27 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int **matalloc(int x, int y)
{
    int     **ret;
    int     zed;

    ret = (int**)malloc(sizeof(int*) * y);
    while (--y >= 0)
    {
        ret[y] = (int*)malloc(sizeof(int) * x);
        zed = 0;
        while(zed < x)
            ret[y][zed++] = 0;
    }
    return (ret);
}