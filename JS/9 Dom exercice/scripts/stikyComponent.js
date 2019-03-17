export default class StikyComponent {
    constructor(element) {
        this.element = element;
        this.header = element.querySelector('.header');
    }

    handleOnScroll = (event) => {
        const scrollPosition = event.srcElement.scrollTop;
        const elementPosition = this.element.offsetTop;
        console.log(scrollPosition, elementPosition);

        if(scrollPosition >= elementPosition) {
            this.header.classList.add('fixed');
        } else {
            this.header.classList.remove('fixed');

        }

    }
}