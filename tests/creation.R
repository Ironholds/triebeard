library(triebeard)

keys <- letters
len <- length(keys)

values_str <- rev(LETTERS) # ensure a copy
values_int <- as.integer(1:len)
values_dbl <- as.double(1:len)

t_str <- create_trie(keys, values_str)
t_int <- create_trie(keys, values_int)
t_dbl <- create_trie(keys, values_dbl)

stopifnot(identical(get_keys(t_str), keys))

stopifnot(identical(get_values(t_str), values_str))
stopifnot(identical(get_values(t_int), values_int))
stopifnot(identical(get_values(t_dbl), values_dbl))

rm(list=c("keys", "values_str", "values_int", "values_dbl"))
invisible(gc())

stopifnot(identical(get_values(t_str), rev(LETTERS)))
stopifnot(identical(get_values(t_int), as.integer(1:len)))
stopifnot(identical(get_values(t_dbl), as.double(1:len)))

rm(list=c("t_str", "t_int", "t_dbl"))
invisible(gc())
