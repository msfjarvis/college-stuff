fun bubbleSort(arr:Array<Int>){
    for(i in 0 until arr.size-1)
        for(j in 0 until arr.size-i-1)
            if (arr[j]>arr[j+1]){
                var temp:Int = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp;
            }
    show(arr)
}
fun show(arr: Array<Int>){
    for (i in 0 until arr.size)
        print("${arr[i]} ")
}
fun main(){
    var arr = arrayOf(5,4,3,2,1)
    bubbleSort(arr)
}