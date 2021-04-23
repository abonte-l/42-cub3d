// #include "../inc/cub3d.h"
#include "cub3d.h"
static int		check_backslash_n(char *buf, char *rest)
{
	size_t			i;
	size_t			len_rest;

	i = 0;
	len_rest = 0;
	if (rest[0] == '\n')
		return (len_rest);
	while (rest[len_rest] != '\n' && rest[len_rest])
		len_rest++;
	while (buf[i] || rest[len_rest] == '\n')
	{
		if (buf[i] == '\n' || rest[len_rest] == '\n')
			return (len_rest);
		i++;
	}
	return (ERROR);
}

int				cpy_lastline(int ret, char **line, char *rest, char *buf)
{
	int		i;
	char	*tmp;

	i = check_backslash_n(buf, rest);
	if (ret == 0 && i != -1)
	{
		rest[i] = '\0';
		*line = ft_strdup(rest);
		tmp = ft_strdup(rest + (i + 1));
		free(rest);
		rest = NULL;
		rest = ft_strdup(tmp);
		free(rest);
		rest = NULL;
		free(tmp);
		tmp = NULL;
		return (ONE_LINE_READ);
	}
	else
	{
		*line = ft_strdup(rest);
		free(rest);
		rest = NULL;
		return (END_OF_FILE);
	}
}

int				read_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	char			*tmp;
	static char		*rest = NULL;
	int				i;
	int				ret;

	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0 || i != -1)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(rest, buf);
		rest = tmp;
		i = check_backslash_n(buf, rest);
		if (i >= 0)
		{
			rest[i] = '\0';
			*line = ft_strdup(rest);
			tmp = ft_strdup(rest + (i + 1));
			free(rest);
			rest = ft_strdup(tmp);
			free(tmp);
			return (ONE_LINE_READ);
		}
	}
	return (cpy_lastline(ret, line, rest, buf) == 1 ? 1 : 0);
}

int				get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFFER_SIZE == 0)
		return (ERROR);
	return (read_line(fd, line) == 1 ? 1 : 0);
}
