int n = derived.size() ;
    vector<int>org (n) ;
    org[0] = 0 ;

    for(int i = 0;i < n-1;i++) {
        org[i+1] = org[i] ^ derived[i] ;
    }

    if(org[n-1] ^ org[0] == derived[n-1]){
        return true ;
    }

    org[0] = 1 ;

    for(int i = 0;i < n-1;i++) {
        org[i+1] = org[i] ^ derived[i] ;
    }

    if(org[n-1] ^ org[0] == derived[n-1]){
        return true ;
    }
    return false ;