#'@export
as.list.trie <- function(trie){
  return(list(keys = get_keys(trie), values = get_values(trie)))
}
