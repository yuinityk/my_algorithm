struct Miller{
    const vector<ll> v = {2,7,61}; // < 4,759,123,141
    //const vector<ll> v = {2,3,5,7,11,13,17}; // < 341,550,071,728,321
    // x^k (mod m)
    ll modpow( ll x, ll k, ll m ){
        ll res = 1;
        while( k ){
          if( k & 1 ){
            res = res * x % m;
          }
          k /= 2;
          x = x * x % m;
        }
        return res;
    }
    // check if n is prime
    bool check( ll n ){
        if( n < 2 ){
          return false;
        }
        ll d = n - 1;
        ll s = 0;
        while( d % 2 == 0 ){
            d /= 2;
            s++;
        }
        for( ll a : v ){
            if( a == n ){
              return true;
            }
            if( modpow( a , d , n ) != 1 ){
              bool ok = true;
              for( ll r = 0; r < s; r++ ){
                if( modpow( a, d * (1LL << r), n ) == n-1 ){
                  ok = false;
                  break;
                }
              }
              if( ok ){
                return false;
              }
            }
        }
        return true;
    }
};

Miller miller;

int main()
{
    int n;
    cin >> n;
    if(miller.check(n)){
        cout << "Prime\n";
    }else{
        cout << "Not Prime\n";
    }
}