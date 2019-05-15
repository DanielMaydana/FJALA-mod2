const actions = {

  SET_USERS: function (payload) {
    return {
      type: 'SET_USERS',
      payload
    }
  },

  //middlewareActions----------------------

  REQUEST_GET_USERS: function (payload) {
    return {
      type: 'REQUEST_GET_USERS',
      payload
    }
  }
}

export default actions;