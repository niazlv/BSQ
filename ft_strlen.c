int	ft_strlen(char *str)
{
	int	k;

	k = 0;
	while (str[k] != '\0')
		k++;
	return (k);
}
