short mu[MAXN] = {0,1};
void mobius(){
  for(int i=1; i<N; ++i){
    if(mu[i]){
      for(int j=i+i; j<N; j+=i) mu[j] -= mu[i];
    }
  }
}
