const fs =require('fs');
const input=fs.readFileSync("./input.txt","utf-8");
const regex = /mul\((\d+),(\d+)\)/g;
sum=0;
while ((match = regex.exec(input)) !== null) {
    a=parseInt(match[1],10);
    b=parseInt(match[2],10);
    sum+=a*b;
}
console.log(sum);