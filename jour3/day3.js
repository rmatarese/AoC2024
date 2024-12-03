const fs =require('fs');
const input=fs.readFileSync("./input.txt","utf-8");
const regex = /mul\((\d{1,3}),(\d{1,3})\)/g;
let sum=0;
for(let match of input.matchAll(regex)){
    a=parseInt(match[1],10);
    b=parseInt(match[2],10);
    sum+=a*b;
}
console.log(sum);

// PARTIE 2

console.log("############PARTIE 2############");

const regexp2 = /(?:don't|do|mul\((\d{1,3}),(\d{1,3})\))/gm;
result=[]
let flag=true;
sum=0;

for(let match of input.matchAll(regexp2)){
    if(match[0]=="don't") flag=false;
    else if(match[0]=='do') flag=true;
    else if(flag){
        a=parseInt(match[1],10);
        b=parseInt(match[2],10);
        sum+=a*b;
    }
}
console.log(sum)
