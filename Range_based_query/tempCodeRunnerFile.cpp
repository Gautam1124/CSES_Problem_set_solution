 built_trie(1,0,0,n-1,n-1);
    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int ans = search(1,0,0,n-1,n-1,a-1,b-1,c-1,d-1);
        cout<<ans<<endl;
    }
