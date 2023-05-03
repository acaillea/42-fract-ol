/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:28:29 by acaillea          #+#    #+#             */
/*   Updated: 2022/01/10 16:28:31 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

char	*ft_strjoin_gnl(char *line, char c)
{
	char	*new;
	int		i;

	i = 0;
	while (line && line[i])
		i++;
	new = (char *)malloc((i + 2) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (line && line[i] && line[i + 1] != '\n')
	{
		new[i] = line[i];
		i++;
	}
	if (line)
		free(line);
	new[i++] = c;
	new[i] = '\0';
	return (new);
}

char	*get_next_line(int const fd)
{
	char	buff[1];
	char	*line;
	int		rd;

	line = NULL;
	while (buff[0] != '\n')
	{
		rd = read(fd, buff, 1);
		if (rd == 0 || rd == -1)
			break ;
		line = ft_strjoin_gnl(line, buff[0]);
	}
	return (line);
}

int	ft_check_for_atof(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-19);
	while (s && s[i])
	{
		if ((s[i] < 48 || s[i] > 57) && s[i] != 45 && s[i] != 46 && s[i] != 10)
			return (-19);
		i++;
	}
	return (0);
}

double	ft_atof(const char *s)
{
	t_atof	atof;

	atof.i = 0;
	atof.res = 0.0;
	atof.sign = 1;
	atof.count = 1;
	if (ft_check_for_atof(s))
		return (-19);
	if (s[atof.i] == '-')
	{
		atof.sign *= -1;
		atof.i++;
	}
	while (s && s[atof.i] && s[atof.i] != '.')
	{
		atof.res = (atof.res * 10.0) + (s[atof.i] - 48);
		atof.i++;
	}
	atof.i++;
	while (s && s[atof.i] && s[atof.i] != '\n')
	{
		atof.res += (s[atof.i++] - 48) / pow(10, atof.count);
		atof.count++;
	}
	return (atof.res * atof.sign);
}
