#'@export
as.list.trie <- function(x, ...){
  return(list(keys = get_keys(x), values = get_values(x)))
}
