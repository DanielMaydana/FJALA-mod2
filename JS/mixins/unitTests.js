const Utilities = require('./utilities');
const assert = require('assert');
const sinon = require('sinon');

describe('Unit Tests', function () {

  describe('DigitCounter Tests', function () {

    it('should return a count of all repeated digits', function () {
      const testSubject = '4510391123456';
      const rightCount = { '1': 3, '3': 2, '4': 2, '5': 2 };
      assert.deepStrictEqual(Utilities.DigitCounter(testSubject), rightCount);
    });

    it('shouldn\'t return a wrong count', function () {
      const testSubject = '4510391123456';
      const wrongCount = { '1': 3, '3': 2, '5': 2 };
      assert.notStrictEqual(Utilities.DigitCounter(testSubject), wrongCount);
    });

  });

  describe('StringifyNumber Tests', function () {

    it('should return a string when passed a number', function () {
      const expectedConversion = '4510391123456';
      assert.equal(Utilities.StringifyNumber(4510391123456), expectedConversion);
    });

    it('should return a string when passed a number in string format', function () {
      const expectedConversion = '4510391123456';
      assert.equal(Utilities.StringifyNumber('4510391123456'), expectedConversion);
    });

    it('should throw an error when passed a string with a letter in between numbers', function () {
      const errorMessage = '\'112A211\' is not a number';
      const wrongString = '112A211';
      try { Utilities.StringifyNumber(wrongString) }
      catch (error) { assert.deepStrictEqual(error, new TypeError(errorMessage)); }
    });

    it('should throw an error when passed a string with no numbers', function () {
      const errorMessage = '\'JavaScript\' is not a number';
      const wrongString = 'JavaScript';
      try { Utilities.StringifyNumber(wrongString) }
      catch (error) { assert.deepStrictEqual(error, new TypeError(errorMessage)); }
    });

  });

  describe('ValidateIsTruthy Tests', function () {

    it('should throw an exception when passed a \'null\' value', function () {
      const nullErrorMessage = '\'null\' is not allowed';
      try { Utilities.ValidateIsTruthy(null) }
      catch (error) { assert.deepStrictEqual(error, new TypeError(nullErrorMessage)); }
    });

    it('should throw an exception when passed a \'false\' value', function () {
      const falseErrorMessage = '\'false\' is not allowed';
      try { Utilities.ValidateIsTruthy(false) }
      catch (error) { assert.deepStrictEqual(error, new TypeError(falseErrorMessage)); }
    });

    it('should throw an exception when passed a \'NaN\' value', function () {
      const nanErrorMessage = '\'null\' is not allowed';
      try { Utilities.ValidateIsTruthy(NaN) }
      catch (error) { assert.deepStrictEqual(error, new TypeError(nanErrorMessage)); }
    });

    it('should throw an exception when passed an empty string', function () {
      const emptyErrorMessage = '\'""\' is not allowed';
      try { Utilities.ValidateIsTruthy('') }
      catch (error) { assert.deepStrictEqual(error, new TypeError(emptyErrorMessage)); }
    });

    it('should throw an exception when passed a \'undefined\' value', function () {
      const undefinedErrorMessage = '\'undefined\' is not allowed';
      try { Utilities.ValidateIsTruthy(undefined) }
      catch (error) { assert.deepStrictEqual(error, new TypeError(undefinedErrorMessage)); }
    });

  });

  describe('ArrayifyString Tests', function () {

    it('should return an array with the same order as the passed string', function () {
      const toArrayify = '123456';
      const expectedArray = ['1', '2', '3', '4', '5', '6'];
      assert.deepStrictEqual(Utilities.ArrayifyString(toArrayify), expectedArray);
    });

    it('should throw an exception when a number is passed', function () {
      const toArrayify = 123456;
      const expectedError = 'toArray.split is not a function';
      try { Utilities.ArrayifyString(toArrayify) }
      catch (error) { assert.deepStrictEqual(error, new TypeError(expectedError)); }
    });

  });

  describe('RemoveDuplicates Tests', function () {

    it('should return array with unique values', function () {
      const toRemove = ['1', '1', '1', '2', '4', '9', '9'];
      const expectedArray = ['1', '2', '4', '9'];
      assert.deepStrictEqual(Utilities.RemoveDuplicates(toRemove), expectedArray);
    });

    it('should return an equal array when there aren\'t any duplicates', function () {
      const toRemove = ['1', '2', '4', '9'];
      const expectedArray = ['1', '2', '4', '9'];
      assert.deepStrictEqual(Utilities.RemoveDuplicates(toRemove), expectedArray);
    });

  });

  describe('SortArray Tests', function () {

    it('should return a sorted array', function () {
      const toSort = ['4', '1', '2', '9'];
      const expectedArray = ['1', '2', '4', '9'];
      assert.deepStrictEqual(Utilities.SortArray(toSort), expectedArray);
    });

    it('should return a sorted array with duplicated values', function () {
      const toSort = ['4', '1', '1', '9'];
      const expectedArray = ['1', '1', '4', '9'];
      assert.deepStrictEqual(Utilities.SortArray(toSort), expectedArray);
    });

  });

  describe('ReverseArray Tests', function () {

    it('should reverse an array', function () {
      const toReverse = ['4', '1', '2', '9'];
      const expectedArray = ['9', '2', '1', '4'];
      assert.deepStrictEqual(Utilities.ReverseArray(toReverse), expectedArray);
    });

  });


});