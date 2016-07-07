#'@export
length.numeric_trie <- function(x){
  return(radix_len_double(x))
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

#'@export
dim.trie <- function(x){
  return(length(x))
}

#'@export
str.trie <- function(object, ...){
  obj_len <- length(object)
  cat(paste0(
    class(object)[3],
    ifelse(obj_len > 1, paste0(" [1:",obj_len, "] "), " "),
    "f"
  ))
  return(invisible())
}
