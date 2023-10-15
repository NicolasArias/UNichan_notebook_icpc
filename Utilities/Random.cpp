// Declare number generator
  mt19937 / mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count())
  // or
  random_device rd
  mt19937 / mt19937_64 rng(rd())

// Use it to shuffle a vector
shuffle(permutation.begin(), permutation.end(), rng)

// Use it to generate a random number between [fr, to]
uniform_int_distribution<T> / uniform_real_distribution<T> dis(fr, to);
  dis(rng)

//code Tovarisch-Klaus
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //high quality random number generator using time as seed
int random(int l, int r){return uniform_int_distribution<int>(l,r)(rng);} //returns a randomb number between [l, r]
//There are many distributions that can be generated
