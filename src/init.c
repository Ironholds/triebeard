#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME:
Check these declarations against the C/Fortran source code.
*/

/* .Call calls */
extern SEXP triebeard_add_trie_integer(SEXP, SEXP, SEXP);
extern SEXP triebeard_add_trie_logical(SEXP, SEXP, SEXP);
extern SEXP triebeard_add_trie_numeric(SEXP, SEXP, SEXP);
extern SEXP triebeard_add_trie_string(SEXP, SEXP, SEXP);
extern SEXP triebeard_get_keys_integer(SEXP);
extern SEXP triebeard_get_keys_logical(SEXP);
extern SEXP triebeard_get_keys_numeric(SEXP);
extern SEXP triebeard_get_keys_string(SEXP);
extern SEXP triebeard_get_values_integer(SEXP);
extern SEXP triebeard_get_values_logical(SEXP);
extern SEXP triebeard_get_values_numeric(SEXP);
extern SEXP triebeard_get_values_string(SEXP);
extern SEXP triebeard_greedy_integer(SEXP, SEXP, SEXP);
extern SEXP triebeard_greedy_logical(SEXP, SEXP, SEXP);
extern SEXP triebeard_greedy_numeric(SEXP, SEXP, SEXP);
extern SEXP triebeard_greedy_string(SEXP, SEXP, SEXP);
extern SEXP triebeard_longest_integer(SEXP, SEXP, SEXP);
extern SEXP triebeard_longest_logical(SEXP, SEXP, SEXP);
extern SEXP triebeard_longest_numeric(SEXP, SEXP, SEXP);
extern SEXP triebeard_longest_string(SEXP, SEXP, SEXP);
extern SEXP triebeard_prefix_integer(SEXP, SEXP, SEXP);
extern SEXP triebeard_prefix_logical(SEXP, SEXP, SEXP);
extern SEXP triebeard_prefix_numeric(SEXP, SEXP, SEXP);
extern SEXP triebeard_prefix_string(SEXP, SEXP, SEXP);
extern SEXP triebeard_radix_create_integer(SEXP, SEXP);
extern SEXP triebeard_radix_create_logical(SEXP, SEXP);
extern SEXP triebeard_radix_create_numeric(SEXP, SEXP);
extern SEXP triebeard_radix_create_string(SEXP, SEXP);
extern SEXP triebeard_radix_len_integer(SEXP);
extern SEXP triebeard_radix_len_logical(SEXP);
extern SEXP triebeard_radix_len_numeric(SEXP);
extern SEXP triebeard_radix_len_string(SEXP);
extern SEXP triebeard_remove_trie_integer(SEXP, SEXP);
extern SEXP triebeard_remove_trie_logical(SEXP, SEXP);
extern SEXP triebeard_remove_trie_numeric(SEXP, SEXP);
extern SEXP triebeard_remove_trie_string(SEXP, SEXP);
extern SEXP triebeard_trie_str_integer(SEXP);
extern SEXP triebeard_trie_str_logical(SEXP);
extern SEXP triebeard_trie_str_numeric(SEXP);
extern SEXP triebeard_trie_str_string(SEXP);

static const R_CallMethodDef CallEntries[] = {
  {"triebeard_add_trie_integer",     (DL_FUNC) &triebeard_add_trie_integer,     3},
  {"triebeard_add_trie_logical",     (DL_FUNC) &triebeard_add_trie_logical,     3},
  {"triebeard_add_trie_numeric",     (DL_FUNC) &triebeard_add_trie_numeric,     3},
  {"triebeard_add_trie_string",      (DL_FUNC) &triebeard_add_trie_string,      3},
  {"triebeard_get_keys_integer",     (DL_FUNC) &triebeard_get_keys_integer,     1},
  {"triebeard_get_keys_logical",     (DL_FUNC) &triebeard_get_keys_logical,     1},
  {"triebeard_get_keys_numeric",     (DL_FUNC) &triebeard_get_keys_numeric,     1},
  {"triebeard_get_keys_string",      (DL_FUNC) &triebeard_get_keys_string,      1},
  {"triebeard_get_values_integer",   (DL_FUNC) &triebeard_get_values_integer,   1},
  {"triebeard_get_values_logical",   (DL_FUNC) &triebeard_get_values_logical,   1},
  {"triebeard_get_values_numeric",   (DL_FUNC) &triebeard_get_values_numeric,   1},
  {"triebeard_get_values_string",    (DL_FUNC) &triebeard_get_values_string,    1},
  {"triebeard_greedy_integer",       (DL_FUNC) &triebeard_greedy_integer,       3},
  {"triebeard_greedy_logical",       (DL_FUNC) &triebeard_greedy_logical,       3},
  {"triebeard_greedy_numeric",       (DL_FUNC) &triebeard_greedy_numeric,       3},
  {"triebeard_greedy_string",        (DL_FUNC) &triebeard_greedy_string,        3},
  {"triebeard_longest_integer",      (DL_FUNC) &triebeard_longest_integer,      3},
  {"triebeard_longest_logical",      (DL_FUNC) &triebeard_longest_logical,      3},
  {"triebeard_longest_numeric",      (DL_FUNC) &triebeard_longest_numeric,      3},
  {"triebeard_longest_string",       (DL_FUNC) &triebeard_longest_string,       3},
  {"triebeard_prefix_integer",       (DL_FUNC) &triebeard_prefix_integer,       3},
  {"triebeard_prefix_logical",       (DL_FUNC) &triebeard_prefix_logical,       3},
  {"triebeard_prefix_numeric",       (DL_FUNC) &triebeard_prefix_numeric,       3},
  {"triebeard_prefix_string",        (DL_FUNC) &triebeard_prefix_string,        3},
  {"triebeard_radix_create_integer", (DL_FUNC) &triebeard_radix_create_integer, 2},
  {"triebeard_radix_create_logical", (DL_FUNC) &triebeard_radix_create_logical, 2},
  {"triebeard_radix_create_numeric", (DL_FUNC) &triebeard_radix_create_numeric, 2},
  {"triebeard_radix_create_string",  (DL_FUNC) &triebeard_radix_create_string,  2},
  {"triebeard_radix_len_integer",    (DL_FUNC) &triebeard_radix_len_integer,    1},
  {"triebeard_radix_len_logical",    (DL_FUNC) &triebeard_radix_len_logical,    1},
  {"triebeard_radix_len_numeric",    (DL_FUNC) &triebeard_radix_len_numeric,    1},
  {"triebeard_radix_len_string",     (DL_FUNC) &triebeard_radix_len_string,     1},
  {"triebeard_remove_trie_integer",  (DL_FUNC) &triebeard_remove_trie_integer,  2},
  {"triebeard_remove_trie_logical",  (DL_FUNC) &triebeard_remove_trie_logical,  2},
  {"triebeard_remove_trie_numeric",  (DL_FUNC) &triebeard_remove_trie_numeric,  2},
  {"triebeard_remove_trie_string",   (DL_FUNC) &triebeard_remove_trie_string,   2},
  {"triebeard_trie_str_integer",     (DL_FUNC) &triebeard_trie_str_integer,     1},
  {"triebeard_trie_str_logical",     (DL_FUNC) &triebeard_trie_str_logical,     1},
  {"triebeard_trie_str_numeric",     (DL_FUNC) &triebeard_trie_str_numeric,     1},
  {"triebeard_trie_str_string",      (DL_FUNC) &triebeard_trie_str_string,      1},
  {NULL, NULL, 0}
};

void R_init_triebeard(DllInfo *dll)
{
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}