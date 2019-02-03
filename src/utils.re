let find = (p: 'a => bool, l: list('a)) => {
  switch (List.find(p, l)) {
  | value => Some(value)
  | exception Not_found => None
  };
};
