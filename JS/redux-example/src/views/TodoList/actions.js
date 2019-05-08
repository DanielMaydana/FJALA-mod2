const actions = {
  ADD_TASK: function (payload) {
    return {
      type: 'ADD_TASK',
      payload
    }
  },

  SET_TASKS: function(payload) {
    return {
      type: 'SET_TASKS',
      payload
    }
  },

  UPDATE_TASK: function (payload) {
    return {
      type: 'UPDATE_TASK',
      payload
    }
  },

  UPDATE_FORM: function(payload) {
    return {
      type: 'UPDATE_FORM',
      payload
    }
  },

  CLEAR_FORM: function(payload) {
    return {
      type: 'CLEAR_FORM',
      payload
    }
  },

  //middlewareActions----------------------

  REQUEST_TASKS: function(payload) {
    return {
      type: 'REQUEST_TASKS',
      payload
    }
  },

  ADD_POST_TASK: function(payload){
    return {
      type: 'ADD_POST_TASK',
      payload
    }
  }
}

export default actions;