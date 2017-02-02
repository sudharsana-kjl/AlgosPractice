// /* Tail recursive function for QuickSort
//  arr[] --> Array to be sorted,
//   low  --> Starting index,
//   high  --> Ending index */
// void quickSort(int arr[], int low, int high)
// {
//     if (low < high)
//     {
//         /* pi is partitioning index, arr[p] is now
//            at right place */
//         int pi = partition(arr, low, high);
 
//         // Separately sort elements before
//         // partition and after partition
//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }
// // See below link for complete running code
// // http://geeksquiz.com/quick-sort/

/* QuickSort after tail call elimination
  arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
start:
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
 
        // Update parameters of recursive call
        // and replace recursive call with goto
        low = pi+1;
        high = high; 
        goto start;
    }
}
// See below link for complete running code
// http://code.geeksforgeeks.org/dbq4yl