export default class ErrorHandler {
    constructor(){
        this.divError = document.createElement("div");
        this.contentDiv = document.createElement("p");
    }

    initErrorHandler(errorHandler){
        this.contentDiv.textContent = errorHandler;
        this.divError.appendChild(this.contentDiv);
    }
}