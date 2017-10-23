/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matmult.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 13:21:11 by rlevine           #+#    #+#             */
/*   Updated: 2017/10/20 13:00:49 by rlevine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

int **matmult_1_4(int ***a1, int ***a2)
{
    int **ret;
    int i;
    int j;

    i = -1;
    j = -1  ;
    ret = matalloc(4, 1);
    while (++j < 4)
    {
        i = -1;
        while (++i < 4)
            ret[0][j] += ((*a1)[0][i] * (*a2)[i][j]);
    }
    return (ret);
}

int **matmult_4_4(int ***a, int ***b)
{
    int **ret;
    int i;
    int j;
    int k;

    i = -1;
    ret = matalloc(4, 4);
    while (++i < 4)
    {
        j = -1;
        while (++j < 4)
        {
            k = -1;
            while (++k < 4)
                ret[i][j] += ((*a)[i][k] * (*b)[k][j]);
        }
    }
    return (ret);
}
/*
int main()
{
    int **a1;
    int **a2;
    int **a3;
    a1 = matalloc(4, 4);
    a2 = matalloc(4, 4);
    a1[0][0] = 1;
    a1[0][1] = 2;
    a1[0][2] = 3;
    a1[0][3] = 4;
    a1[1][0] = 1;
    a1[1][1] = 2;
    a1[1][2] = 3;
    a1[1][3] = 4;
    a1[2][0] = 1;
    a1[2][1] = 2;
    a1[2][2] = 3;
    a1[2][3] = 4;
    a1[3][0] = 1;
    a1[3][1] = 2;
    a1[3][2] = 3;
    a1[3][3] = 4;

    a2[0][0] = 1;
    a2[0][1] = 2;
    a2[0][2] = 3;
    a2[0][3] = 4;
    a2[1][0] = 1;
    a2[1][1] = 2;
    a2[1][2] = 3;
    a2[1][3] = 4;
    a2[2][0] = 1;
    a2[2][1] = 2;
    a2[2][2] = 3;
    a2[2][3] = 4;
    a2[3][0] = 1;
    a2[3][1] = 2;
    a2[3][2] = 3;
    a2[3][3] = 4;

    a3 = matmult_4_4(&a1, &a2);
    printf("%i, %i, %i, %i\n", a3[0][0], a3[0][1], a3[0][2], a3[0][3]);
    printf("%i, %i, %i, %i\n", a3[1][0], a3[1][1], a3[1][2], a3[1][3]);
    printf("%i, %i, %i, %i\n", a3[2][0], a3[2][1], a3[2][2], a3[2][3]);
    printf("%i, %i, %i, %i\n", a3[3][0], a3[3][1], a3[3][2], a3[3][3]);
    }
    */