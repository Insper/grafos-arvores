import {LitElement, html, css} from 'https://cdn.jsdelivr.net/gh/lit/dist@2/core/lit-core.min.js';


export class AhButton extends LitElement {
  static properties = {
    href: {type: String},
    primary: {type: Boolean},
  };

  static styles = css`
    a {
      margin-left: auto;
      margin-right: auto;
      max-width: 15em;
      display: block;
      text-align: center;
    }
  `;

  constructor() {
    super();
    this.href = "#";
    this.primary = false;
  }

  render() {
    let isPrimary = "";
    if (this.primary) {
      isPrimary = "ah-button--primary";
    }
    return html`
      <link rel="stylesheet" href="https://insper.github.io/tecnicas-de-programacao/assets/css/main.css">
      <div>
        <a href="${this.href}" class="ah-button ${isPrimary}"><slot></slot></a>
      </div>
    `;
  }
}
customElements.define('ah-button', AhButton);
