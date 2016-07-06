#'@export
length.numeric_trie <- function(x){
  return(radix_len_str(x))
}

#'@export
length.integer_trie <- function(x){
  return(radix_len_int(x))
}

#'@export
length.string_trie <- function(x){
  return(radix_len_str(x))
}

#'@export
length.bool_trie <- function(x){
  return(radix_len_bool(x))
}

