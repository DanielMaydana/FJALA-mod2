function DigitCounter(toCount) {
  let totalCount = {};
  for (let i = 0; i < toCount.length; i++) {
    let digit = toCount[i];
    if (typeof totalCount[digit] === 'undefined') totalCount[digit] = 1;
    else totalCount[digit]++;
  }

  for (var property in totalCount) {
    if (totalCount[property] <= 1) {
      delete totalCount[property];
    }
  }
  return totalCount;
}

function StringifyNumber(toString) {
  const regex = new RegExp('^\\d+$', 'g');
  const converted = String(toString);
  return regex.test(converted) ? converted : new TypeError(`'${toString} is not a number`);
}

function ValidateIsTruthy(toValidate) {
  if (toValidate !== '0' && !toValidate) {
    throw new TypeError(`'${JSON.stringify(toValidate)}' is not allowed`);
  }
}

function ArrayifyString(toArray) {
  return toArray.split('');
}

function RemoveDuplicates(toRemove) {
  return Array.from(new Set(toRemove));
}

function SortArray(toSort) {
  return toSort.sort();
}

function ReverseArray(toReverse) {
  return toReverse.reverse();
};

function SuperSort(toSuperSort) {

};


module.exports = {
  DigitCounter,
  StringifyNumber,
  ValidateIsTruthy,
  ArrayifyString,
  SortArray,
  ReverseArray,
  RemoveDuplicates,
}