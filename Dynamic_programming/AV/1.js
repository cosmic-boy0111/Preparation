var obj = {
    item : ['abc','dce'],
    hsn : ['hsn1','hsn2']
}

var size = obj.item.length;

var arr = []
for (let i = 0; i < size; i++) {
    arr[i] = []
}

for (const property in obj) {
    obj[property].forEach((element,index) => {
        arr[index].push(element)
    });
}
  
console.log(arr);
