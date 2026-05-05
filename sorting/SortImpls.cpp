#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums, int start, int mid, int end);

int Partition(vector<int>& nums, int start, int end);

void BubbleSort1(vector<int>& nums,int start, int end)
{
    for(int i = end - 1; i >= start; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

void BubbleSort2(vector<int>& nums, int start, int end)
{
    bool notDone = false;

    while(!notDone)
    {
        notDone = true;
        
        for(int i = start; i < end - 1; i++)
        {
            if(nums[i] > nums[i + 1])
            {
                swap(nums[i], nums[i + 1]);
                notDone = false;
            }
        }
    }
}

void BubbleSort3(vector<int>& nums, int index1, int index2)
{
    if(index1 < 0 || index2 > nums.size())
    {
        cout << "Invalid index's for array size.\n";
    }
    bool notDone = false;

    while(!notDone)
    {
        notDone = true;
        
        for(int i = index1; i < index2 - 1; i++)
        {
            if(nums[i] > nums[i + 1])
            {
                swap(nums[i], nums[i + 1]);
                notDone = false;
            }
        }
    }
}

void InsertionSort(vector<int>& nums,int start, int end)
{
    for (int i = 1; i < end; i++)
    {
        int v = nums[i];
        int j = i-1;
        while (j >= 0 && nums[j] > v)
        {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = v;
    }
}

void merge(vector<int>& nums, int start, int mid, int end)
{
    int num1 = mid - start + 1;
    int num2 = end - mid;

    vector<int> left(num1), right(num2);

    for(int i = 0; i < num1; i++)
    {
        left[i] = nums[start + i];
    }

    for(int j = 0; j < num2; j++)
    {
        right[j] = nums[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = start;

    while(i < num1 && j < num2)
    {
        if(left[i] <= right[j])
        {
            nums[k] = left[i];
            i++;
        }
        else
        {
            nums[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < num1)
    {
        nums[k] = left[i];
        i++;
        k++;
    }

    while(j < num2)
    {
        nums[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort(vector<int>& nums, int start, int end)
{
    if(start < end)
    {
        int mid = start + (end - start) / 2;
        MergeSort(nums, start, mid);
        MergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }
}

int Partition(vector<int>& nums, int start, int end)
{
    int mid = start + (end - start) / 2;

    if(nums[start] > nums[mid])
    {
        swap(nums[start], nums[mid]);
    }

    if(nums[start] > nums[end])
    {
        swap(nums[start], nums[end]);
    }

    if(nums[mid] > nums[end])
    {
        swap(nums[mid], nums[end]);
    }

    int pivot = nums[mid];

    swap(nums[mid], nums[end]);

    int i = (start - 1);

    for(int j = start; j <= end - 1; j++)
    {
        if(nums[j] <= pivot)
        {
            i++;
            swap(nums[i], nums[j]);
        }
    }

    swap(nums[i + 1], nums[end]);

    return(i + 1);
}

void QuickSort(vector<int>& nums, int start, int end)
{
    if(start < end)
    {
        int partition = Partition(nums, start, end);
        QuickSort(nums, start, partition - 1);
        QuickSort(nums, partition + 1, end);
    }
}

void ShellSort(vector<int>& nums, int start, int end)
{
    int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};

    for(int gap : gaps)
    {
        for(int i = start + gap; i < end; i++)
        {
            int num = nums[i];
            int j = 0;

            for(j = i; (j >= start + gap) && (nums[j - gap] > num); j -= gap)
            {
                nums[j] = nums[j - gap];
            }

            nums[j] = num;
        }
    }
}