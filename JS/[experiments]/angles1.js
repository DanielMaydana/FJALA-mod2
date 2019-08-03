function ArchPointsGenerator(diameter, dialDiameter, steps) {

  const conversion = Math.PI / 180;
  const stepAngle = 360 / steps;
  const radius = (diameter - dialDiameter) / 2;
  let points = [];
  let angleT;

  function Round(toRound, decPlaces = 2) {
    return Math.round(toRound * decPlaces * 10) / (decPlaces * 10);
  }

  for (let i = 1; i <= steps; i++) {

    angleT = conversion * stepAngle * i;

    points.push(
      {
        n: i,
        xPoint: Round(radius + Math.cos(angleT) * radius),
        yPoint: Round(radius + Math.sin(angleT) * radius),
      }
    )
  }
  return points;
}

console.log(ArchPointsGenerator(120, 16, 10));