const stepAngle = 36;
const conversion = Math.PI / 180;
const radius = 60;
let points = [];

for (let i = 1; i <= 10; i++) {
  points.push(
    {
      x: radius + Math.cos(i * stepAngle * conversion),
      y: radius + Math.sin(i * stepAngle * conversion),
    }
  )
}

console.log(Math.cos(conversion));
