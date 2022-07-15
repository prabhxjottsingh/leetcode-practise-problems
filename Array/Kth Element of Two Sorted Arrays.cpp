class Solution
{
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int resCount = 1;
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (arr1[i] <= arr2[j])
            {
                if (resCount == k)
                    return arr1[i];
                resCount++;
                i++;
            }
            else
            {
                if (resCount == k)
                    return arr2[j];
                j++;
                resCount++;
            }
        }
        while (i < n)
        {
            if (resCount == k)
                return arr1[i];
            i++;
            resCount++;
        }
        while (j < m)
        {
            if (resCount == k)
                return arr2[j];
            j++;
            resCount++;
        }
        return -1;
    }
};