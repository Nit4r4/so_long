/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:59:03 by vferraro          #+#    #+#             */
/*   Updated: 2022/04/27 16:15:11 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Finds the first occurrence of the sub-string word in the string str.
 * Returns NULL if word was not found.
 */
char *ft_strstr(const char *str, const char *word)
{
    if (!*word)
        return (char *) str;

    const char    word_first  = *word;

    /* Runs strchr() on the first section of the str as it has a lower
    * algorithmic complexity for discarding the first non-matching characters.
    * Then check that first character of word is not in the str
    */
    str = ft_strchr(str, word_first);
    if (!str)
        return NULL;

    /* First characters of str and word are the same now. Both are
    * guaranteed to be at least one character long.
    * Now computes the sum of the first word_len characters of str
    * minus the sum of characters values of word.
    */
    const char   *i_str    = str + 1
             ,   *i_word      = word   + 1;

    unsigned int  sums_diff     = *str;
    bool          identical     = true;

    while (*i_str && *i_word) {
        sums_diff += *i_str;
        sums_diff -= *i_word;
        identical &= *i_str++ == *i_word++;
    }

    /* i_str now references the (word_len + 1)-th character. 
    * Check that str is smaller than word.
    */
    if (*i_word)
        return NULL;
    else if (identical)
        return (char *) str;

    size_t        word_len    = i_word - word;
    size_t        word_len_1  = word_len - 1;

    /* Loops for the remaining of the str, updating the sum iteratively.*/
    const char   *sub_start;
    for (sub_start = str; *i_str; i_str++) {
        sums_diff -= *sub_start++;
        sums_diff += *i_str;

        /* Since the sum of the characters is already known to be equal at that
        // point, it is enough to check just word_len-1 characters for equality
        */
        if (
               sums_diff == 0
            && word_first == *sub_start
            && ft_memcmp(sub_start, word, word_len_1) == 0
        )
            return (char *) sub_start;
    }

    return NULL;
}