struct mat{
    int numrow, numcol;
    vector<vector<int>> data;

    mat(int n = 0, int m = 0){
        numrow = n; numcol = m;
        data.assign(numrow, vector<int> (numcol, 0));
    }

    mat operator * (const mat &trans){
        assert(numcol == trans.numrow);
        mat res(numrow, trans.numcol);

        for(int i = 0; i < numrow; i++) for(int j = 0; j < numcol; j++){
            for(int k = 0; k < trans.numcol; k++){
                (res.data[i][k] += 1ll * data[i][j] * trans.data[j][k] % MOD) %= MOD;
            }
        } return res;
    }

    mat pow(long long k){
        assert(k > 0);
        k--;
        mat res = (*this), tmp = res;
        for (; k; k >>= 1, tmp = tmp * tmp)
            if (k & 1) res = res * tmp;
        return res;
    }
};
