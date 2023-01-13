class Solution
{
public:
    vector<int> leaders(int a[], int n)
    {
        vector<int> wyn;
        int max_val = -1e9-5;
        for (int i = n-1; i >= 0; --i)
        {
            max_val = max(max_val,a[i]);
            if (a[i] == max_val)
                wyn.push_back(a[i]);
        }
        sort(wyn.begin(),wyn.end(),greater<int>());
        return wyn;
    }
};