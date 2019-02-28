// create a Object Clock,
// it has configurable reminder functions( start, cancel, addNewReminder, deleteReminder)

// start should start all reminders in the object you can use timeout() function to
// execute in the time of the reminder (MS)
// stop should cancel all scheduled (timeouts) reminders clearTimeout to cancel timeout reminders

// addNewReminder should add a new reminder to the object
// deleteReminder should delete a reminder params (reminderId) ej. '001'

    var clock = {

        ongoingFlag : false,
        
        queuedList : [],

        enqueue : function(remindertoAdd){
        
            this.queuedList.push(remindertoAdd);
        },

        start : function(){
            
        },

        cancel : function()
        {

        },

        addNewReminder : function()
        {

        },

        deleteReminder : function(remindertoDel)
        {

        }
    };

//reminder Object is...
    const reminder = {
    id: '001',
    text: 'wake me up',
    time: 10000//ms
    };
    
    const reminder2 = {
    id: '002',
    text: 'take my dr. pills',
    time: 5000//ms
    };
    
    const reminder3 = {
    id: '003',
    text: 'take my dr. pills',
    time: 15000//ms
    };
    
    clock.enqueue(reminder);
    clock.enqueue(reminder2);
    clock.enqueue(reminder3);
    clock.start();
