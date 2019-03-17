// its not nesesary to read this
// use this methods instead
const DB = new PouchDB('to_do_list');

const initialState = {
  _id: 'list',
  tasks: []
};

export default class DataBase {
  constructor() {
    this.dataBase = DB;
    this.initDataBase();
  }

  async initDataBase() {
    try {
      await this.dataBase.get('list');
    } catch (error) {
      if(error.name === 'not_found') {
        try {
          this.dataBase.post(initialState);
        } catch(error) {
          console.log(error);
        }
      }
    }
  }

  async getList() {
    try {
      const doc = await this.dataBase.get('list');
      return doc.tasks || [];
    } catch(error) {
      if(error.name === 'not_found') {
        return [];
      }
    }
  }

  async addTask(task) {
    const newTask = {
      id: new Date().getTime(),
      title: task.title,
      isDone: task.isDone || false,
    };
  
    try {
      const doc = await this.dataBase.get('list');
      doc.tasks = doc.tasks || [];
      doc.tasks.push(newTask);
      await this.dataBase.put(doc);
      return newTask;
    } catch (error) {
      console.log(error);
    }
  }

  async removeTask(id) {
    try {
      const doc = await this.dataBase.get('list');
      if(doc.tasks) {
        const index = doc.tasks.findIndex(task => task.id === id);
        doc.tasks.splice(index, 1);
      }
      return await this.dataBase.put(doc);
    } catch (error) {
      console.log(error);
    }
  }

  async updateTask(payload) {
    try {
      const doc = await this.dataBase.get('list');
      if(doc.tasks) {
        let task = doc.tasks.find(task => task.id === id);
        task.title = payload.title || task.title;
        task.isDone = payload.isDone;
      }
      return await this.dataBase.put(doc);
    } catch (error) {
      console.log(error);
    }
  }
};