/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:01:41 by giodos-s          #+#    #+#             */
/*   Updated: 2025/11/16 21:01:41 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static const char	*ft_skip_white_spaces(const char *string)
{
	while (*string == ' ' || (*string >= 9 && *string <= 13))
		string++;
	return (string);
}

static const char	*ft_check_sign(int *sign, const char *string)
{
	*sign = 1;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			*sign = -1;
		string++;
	}
	return (string);
}

/* ************************************************************************** */
/*                                FT_ATOI                                     */
/*                                                                            */
/*   Converts a numeric string to an integer. Skips leading whitespaces and   */
/*   handles an optional sign.                                                */
/*                                                                            */
/* ************************************************************************** */
int	ft_atoi(const char *string)
{
	int	result;
	int	sign;

	result = 0;
	string = ft_skip_white_spaces(string);
	string = ft_check_sign(&sign, string);
	while (*string >= '0' && *string <= '9')
	{
		result = (result * 10) + (*string - '0');
		string++;
	}
	return (result * sign);
}
